import json
from jinja2 import FileSystemLoader, Environment
import os.path

# JSON models
data_types_model_filename = "GeneratorEngine/Models/DataType.json"
components_model_filename = "GeneratorEngine/Models/Components.json"
systems_model_filename = "GeneratorEngine/Models/Systems.json"
input_mapping_model_filename = "GeneratorEngine/Models/InputMapping.json"

# Jinja2 templates
data_types_template_filename = "GeneratorEngine/Templates/DataType.h.jinja"
component_template_filename = "GeneratorEngine/Templates/Component.h.jinja"
signature_template_filename = "GeneratorEngine/Templates/Signature.h.jinja"
component_manager_h_template_filename = "GeneratorEngine/Templates/ComponentManager.h.jinja"
component_manager_cpp_template_filename = "GeneratorEngine/Templates/ComponentManager.cpp.jinja"
system_manager_cmakelists_template_filename = "GeneratorEngine/Templates/SystemManagerCMakeLists.txt.jinja"
system_h_template_filename = "GeneratorEngine/Templates/System.h.jinja"
system_cpp_template_filename = "GeneratorEngine/Templates/System.cpp.jinja"
system_manager_h_template_filename = "GeneratorEngine/Templates/SystemManager.h.jinja"
system_manager_cpp_template_filename = "GeneratorEngine/Templates/SystemManager.cpp.jinja"
input_mapping_h_template_filename = "GeneratorEngine/Templates/InputMapping.h.jinja"
input_mapping_cpp_template_filename = "GeneratorEngine/Templates/InputMapping.cpp.jinja"

# Output directories
data_types_output_dir = "Core/Src/DataType"
components_output_dir = "Core/Src/Component"
entity_output_dir = "Core/Src/Entity"
systems_output_dir = "Core/Src/System"
input_mapping_output_dir = "Core/Src/Input"

# -----------
# Load models
# -----------
with open(data_types_model_filename, "r") as f:
  data_types_model = json.load(f)
  
with open(components_model_filename, "r") as f:
  components_model = json.load(f)
  
with open(systems_model_filename, "r") as f:
  systems_model = json.load(f)
  
with open(input_mapping_model_filename, "r") as f:
  input_mapping_model = json.load(f)

# ---------------------
# Setup template loader
# ---------------------
template_loader = FileSystemLoader(searchpath="./")
template_env = Environment(loader=template_loader)

# ---------
# Signature
# ---------
component_signature_masks = {}

component_index = 1
for component in components_model:
  component_signature_masks[component] = "0x{}".format(hex(component_index)[2:].upper())
  component_index = component_index << 1

# Get template
signature_template = template_env.get_template(signature_template_filename)

# Render template
with open("{}/Signature.hpp".format(entity_output_dir), "w") as f:
  f.write(signature_template.render(components_model=components_model, component_signature_masks=component_signature_masks))

# ----------
# Data types
# ----------
# Get template
data_types_template = template_env.get_template(data_types_template_filename)

# Render template
for data_type in data_types_model:
  with open("{}/{}.hpp".format(data_types_output_dir, data_type), "w") as f:
    f.write(data_types_template.render(data_type=data_type, data_types_model=data_types_model[data_type]))

# ---------
# Component
# ---------
# Get templates
component_template = template_env.get_template(component_template_filename)
component_manager_h_template = template_env.get_template(component_manager_h_template_filename)
component_manager_cpp_template = template_env.get_template(component_manager_cpp_template_filename)

# Render templates
for component in components_model:
  # Component.hpp
  with open("{}/{}.hpp".format(components_output_dir, component), "w") as f:
    f.write(component_template.render(component=component, parameters=components_model[component]))
# Component Manager
with open("{}/ComponentManager.hpp".format(components_output_dir), "w") as f:
  f.write(component_manager_h_template.render(components_model=components_model))
with open("{}/ComponentManager.cpp".format(components_output_dir), "w") as f:
  f.write(component_manager_cpp_template.render(components_model=components_model))

# ------
# System
# ------
# Get templates
system_manager_cmakelists_template = template_env.get_template(system_manager_cmakelists_template_filename)
system_h_template = template_env.get_template(system_h_template_filename)
system_cpp_template = template_env.get_template(system_cpp_template_filename)
system_manager_h_template = template_env.get_template(system_manager_h_template_filename)
system_manager_cpp_template = template_env.get_template(system_manager_cpp_template_filename)

# Render templates
for system in systems_model:
  # System.hpp
  with open("{}/{}System.hpp".format(systems_output_dir, system), "w") as f:
    f.write(system_h_template.render(system=system, components=systems_model[system]))
  
  # System.cpp
  if not os.path.isfile("{}/{}System.cpp".format(systems_output_dir, system)):
    with open("{}/{}System.cpp".format(systems_output_dir, system), "w") as f:
      f.write(system_cpp_template.render(system=system, components=systems_model[system]))

# System Manager
with open("{}/SystemManager.hpp".format(systems_output_dir), "w") as f:
  f.write(system_manager_h_template.render(systems_model=systems_model))
with open("{}/SystemManager.cpp".format(systems_output_dir), "w") as f:
  f.write(system_manager_cpp_template.render(systems_model=systems_model))

# System CMakeLists.txt
with open("{}/CMakeLists.txt".format(systems_output_dir), "w") as f:
  f.write(system_manager_cmakelists_template.render(systems_model=systems_model))

# -----
# Input
# -----
# Get template
input_mapping_h_template = template_env.get_template(input_mapping_h_template_filename)
input_mapping_cpp_template = template_env.get_template(input_mapping_cpp_template_filename)

# InputMapping.hpp
with open("{}/InputMapping.hpp".format(input_mapping_output_dir), "w") as f:
  f.write(input_mapping_h_template.render(input_mapping=input_mapping_model))

# InputMapping.cpp
with open("{}/InputMapping.cpp".format(input_mapping_output_dir), "w") as f:
  f.write(input_mapping_cpp_template.render(input_mapping=input_mapping_model))
