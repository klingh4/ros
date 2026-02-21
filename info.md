# Publisher
efter att ha skrivit klart koden så ska vi sedan gå in i våran pkg:s (ros) CMakeList.txt fil och läga till våra dependencies, se de som är utkommenterat. Sedan i början la jag till COMPONENTS som antar jag är includes som behövs för att köra ros noden.

När jag är klar kör jag catkin_make för att bygga min nod. Ska stå "Built target "publisher_node"" eftersom min publisher fil heter publisher_node.

Efter det kör jag soruce devel/setup.bash.

## Starta/Läsa av

För att starta så kör man >roscore i en ny terminal för att starta programmet. 

Sedan för att starta publishern så kör vi >rosrun ros (mitt pkg) publisher_node (min node).
Kommer inte göra något utan kommer bli en blank space vilket indikerar på att den funkar. 

för att kolla vilka topics som finns kör >rostopic list, i en ny terminal

för att läsa av i terminalen så kör vi >rostopic echo /ros (mitt pkg).
