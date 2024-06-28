import json
from jinja2 import FileSystemLoader, Environment
import os.path
import sys

if len(sys.argv) < 2:
  print("No project file given")
  sys.exit()

project_filename = sys.argv[1]
project_path = os.path.dirname(project_filename)

# JSON models
data_types_model_filename = "GeneratorEngine/Models/DataTypes.json"
components_model_filename = "GeneratorEngine/Models/Components.json"

main_template_filename = "GeneratorEngine/Templates/Main.cpp.jinja"
project_cmakelists_template_filename = "GeneratorEngine/Templates/ProjectCMakeLists.txt.jinja"

# -----------
# Load models
# -----------
with open(data_types_model_filename, "r") as f:
  data_types_model = json.load(f)
  
with open(components_model_filename, "r") as f:
  components_model = json.load(f)

with open(project_filename, "r") as f:
  project_info = json.load(f)

scenes = []

for scene_filename in project_info["Scenes"]:
  with open(os.path.join(project_path,scene_filename), "r") as f:
    scenes.append(json.load(f))

# ---------------------
# Setup template loader
# ---------------------
template_loader = FileSystemLoader(searchpath="./")
template_env = Environment(loader=template_loader)

main_template = template_env.get_template(main_template_filename)
project_cmakelists_template = template_env.get_template(project_cmakelists_template_filename)


with open("{}/Main.cpp".format(project_path), "w") as f:
  f.write(main_template.render(project_info=project_info, scenes=scenes))

with open("{}/CMakeLists.txt".format(project_path), "w") as f:
  f.write(project_cmakelists_template.render(project_info=project_info))