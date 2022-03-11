# #!/bin/sh
./dakota_cleanup
dakota -i dakota_of.in -o run.out 
#dakota -i dakota_of.in -o run.out > stdout.out | tail -f stdout.out
