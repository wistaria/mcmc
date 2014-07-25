FOREACH(name random dimension antithetic separation importance)
  add_executable(${name} ${name}.cpp)
  add_diff_test(${name})
ENDFOREACH(name)
