root_dir = os.getcwd()
build_dir = path.join(root_dir, 'build')
bin_dir = path.join(build_dir, 'bin')
lib_dir = path.join(build_dir, 'lib')
obj_dir = path.join(build_dir, 'obj')
project_dir = path.join(root_dir, 'projects')

solution 'Playground'
  configurations {'Debug', 'Release'}
  language 'C++'
  location (project_dir)
  targetdir (bin_dir)
  startproject 'Test'
  objdir (obj_dir)
  vpaths
  {
    ['Header Files'] = {'**.h'},
    ['Source Files'] = {'**.cpp', '**.c'},
    ['Shaders']      = {'**.vert', '**.frag'},
    ['OpenGL'] = { 'source/demos/GL/*'}
    
  }
  defines{}
  flags{ 'Unicode'}
  platforms {'x86', 'x86_64'}
  filter 'platforms:x86'
    architecture 'x86'
  filter 'platforms:x86_64'
    architecture 'x86_64'

project 'Playground'
  kind 'ConsoleApp'
  location(path.join(project_dir, 'Playground'))
  language 'C++'
  files 
  {
    'client/cpp/source/**',
    'client/cpp/include/**'
  }
  includedirs{ 'client/cpp/include' }
  configuration 'Debug'
    flags{'Symbols'}
  configuration 'Release'
    flags{'Optimize'}

project 'PlaygroundSharp'
    kind 'ConsoleApp'
    location(path.join(project_dir, 'PlaygroundSharp'))
    language 'C#'

    --targetdir (build_dir)
    files 
    {
      'client/csharp/source/**',
      'client/csharp/include/**'
    }
    includedirs
    {
      'client/csharp/include'
    }
    configuration 'Debug'
      debugargs { "World" }
      flags{'Symbols'}
    configuration 'Release'
      flags{'Optimize'}

group 'Contrib libs'
  dofile('../../github/unittest-cpp/unittest.lua')

group 'Tests'
  project 'Test'
    kind 'ConsoleApp'
    location(path.join(project_dir, 'Test'))
    language 'C++'

    targetdir (build_dir)
    files 
    {
      'client/cpp/source/test/**',
      'client/cpp/include/test/**'
    }
    includedirs
    {
      'client/cpp/include',
      '../../github/unittest-cpp/Unittest++'
    }
    links
    {
      'Unittest',
    }
    postbuildcommands { '$(OutDir)$(TargetFileName)' }
    configuration 'Debug'
      flags{'Symbols'}
    configuration 'Release'
      flags{'Optimize'}

  project 'TestSharp'
    kind 'ConsoleApp'
    location(path.join(project_dir, 'Test'))
    language 'C#'
    targetdir (build_dir)
    files 
    {
      'client/csharp/source/test/**',
      'client/csharp/include/test/**'
    }
    includedirs
    {
      'client/csharp/include',
      '../../github/unittest-cpp/Unittest++'
    }
    links
    {
      'Unittest',
    }
    postbuildcommands { '$(OutDir)$(TargetFileName)' }
    configuration 'Debug'
      flags{'Symbols'}
    configuration 'Release'
      flags{'Optimize'}
