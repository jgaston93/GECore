import json
from jinja2 import FileSystemLoader, Environment

# JSON models
data_types_model_filename = "GeneratorEngine/Models/DataTypes.json"
components_model_filename = "GeneratorEngine/Models/Components.json"

# Jinja2 templates
data_types_template_filename = "GeneratorEngine/Templates/DataType.h.jinja"
components_template_filename = "GeneratorEngine/Templates/Component.h.jinja"

# Output directories
data_types_output_dir = "Src/DataTypes/"
components_output_dir = "Src/Components/"

# Load models
with open(data_types_model_filename, "r") as f:
  data_types_model = json.load(f)
  
with open(components_model_filename, "r") as f:
  components_model = json.load(f)

# Get templates
template_loader = FileSystemLoader(searchpath="./")
template_env = Environment(loader=template_loader)

data_types_template = template_env.get_template(data_types_template_filename)
components_template = template_env.get_template(components_template_filename)

for data_type in data_types_model:
  with open("{}/{}.hpp".format(data_types_output_dir, data_type), "w") as f:
    f.write(data_types_template.render(data_type=data_type, cpp_data_type=data_types_model[data_type]["cpp_data_type"]))

for component in components_model:
  with open("{}/{}.hpp".format(components_output_dir, component), "w") as f:
    f.write(components_template.render(component=component, parameters=components_model[component]))
