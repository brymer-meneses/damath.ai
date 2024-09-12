project(
    'damath.ai',
    'cpp',
    default_options: ['cpp_std=c++23'],
    meson_version: '>=1.5.1',
)

cc = meson.get_compiler('cpp')

deps = []
files = []
includes = []

deps += [cc.find_library('tensorflow_cc')]

files += [
    'src/engine.cc',

    'src/damath/board.cc',

    'src/mcts/node.cc',

    'src/neural/network.cc',

]

includes += ['src']

executable(
    'damath',
    'src/main.cc',
    files,
    include_directories: includes,
    dependencies: deps,
    install: true,
)