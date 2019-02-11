1 :
                      ==STACK==
                       ARGV[1]
                       ARGV[2]
                       ARGV[3]
2 :
  path1               ==STACK==
    file1
    file2
    dir1        ---> push front ----> dir1
    file3
    dir2        ---> push back  ----> dir2

 3 :
                    ==JOINT STACK==
                  dir1 -----> removes
                        dir2
                       ARGV[2]
                       ARGV[3]
 4 :
   path2               *STACK
    file4
    dir3       ---> push front ----> dir3
    file5
    dir4       ---> push back  ----> dir4
    file6

 5 :
                    ==JOINT STACK==
                  dir3 -----> remove
                        dir4
                        dir2
                       ARGV[2]
                       ARGV[3]
