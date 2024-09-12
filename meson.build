project(
    'damath.ai',
    'cpp',
    default_options: [
      'cpp_std=c++23', 
      'warning_level=3'
    ],
    meson_version: '>=1.5.1',
)

cpp_args = []

# add cpp warnings
cpp_args += [
  '-Wunused', 
  '-Wpedantic', 
  '-Wself-assign',
  '-Wimplicit-fallthrough',
  '-Wctad-maybe-unsupported',
  '-Wmissing-prototypes',
  '-Wzero-as-null-pointer-constant',
  '-Wdelete-non-virtual-dtor',

  # ignore warnings on 'torch/'
  '--system-header-prefix=torch/',
]

add_project_arguments(
  cpp_args,
  language: 'cpp',
)

deps = []
files = []
includes = []

deps += [dependency('torch', version: '2.2.0', modules: 'torch')]

includes += ['src']

executable(
    'damath',
    'src/main.cc',
    files,
    include_directories: includes,
    dependencies: deps,
    install: true,
)
