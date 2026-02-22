# TACK
Stort tack till Emil Vidmakr för den härliga genomgången.
https://www.youtube.com/playlist?list=PLAjUtIp46jDdv1U7I0tJlJTmjnYcczJSN

# Lite förklaringar
När jag menar "root" så menar jag att det körs i workspace foldern där man kan se devel, build och src.

När jag menar pkg så är det en förkorting utav package vilket vi jobbar med. min heter ros. och finns i /src


# Publisher
efter att ha skrivit klart koden så ska vi sedan gå in i våran pkg:s (ros) CMakeList.txt fil och läga till våra dependencies, se de som är utkommenterat. Sedan i början la jag till COMPONENTS som antar jag är includes som behövs för att köra ros noden.

När jag är klar kör jag ">"catkin_make" i "root" för att bygga min nod. Ska stå "Built target "publisher_node"" eftersom min publisher fil heter publisher_node.

Efter det kör jag soruce devel/setup.bash. Tror det bara behöver göras första gången.

## Starta/Läsa av

För att starta så kör man ">roscore" i en ny terminal för att starta programmet. 

Sedan för att starta publishern så kör vi ">rosrun ros (mitt pkg) publisher_node (min node)". Detta körs i "root.

Kommer inte göra något utan kommer bli en blank space vilket indikerar på att den funkar. 

för att kolla vilka topics som finns kör ">rostopic list", i en ny terminal

för att läsa av i terminalen så kör vi ">rostopic echo /ros" (mitt pkg).

# Subcriber
After writing the subsriber dont forget to update the pkgs CMakeLists.txt file

## Starta/Läsa av
Gå till workspace "root" ok kör ">catkin_make" står ">[100%] Built target subscriber_node", om den byggdes utan error.

starta i en ny terminal ros genom att köra roscore. 

Sedan i en annan terminal kör i "root" kör ">source devel/bash. och sedan starta publisher noden (se tidigare i texten).

Sedan i en annan terminal kör i "root" kör ">source devel/bash. och sedan starta subsriber noden ">rosrun ros (mitt pkg) subsriber_node (min node)".

# Custom MSG type
Skapa en folder i vårat pkg (ros)

När det kommer till att skapa ett costum msg så behöver vi bara förklara i mitt fall person_data.msg filen typen av variabel och variabelnamn. Som man kan se så har vi "string name" etc.

för att lägga till vårat custom msg så måste vi lägga till dependencies i package.xml filen. en build och en executable dependencies se kommentarer för att förstå.

Sednan går vi in i CMakeLists.txt för vårat pkg då har jag lagt till message_generation och tog bort genmsg
se kommentarer för add_message_files()

Sedan är det bara att specificera din msgs så istället för att det står std_msgs::String så ska det i mitt fall stå ros::person_data

## Starta/Läsa

Kör i "root" ">catkin_make" för att bygga ska stå "[100%] Built target publisher_node
[100%] Built target subscriber_node" då är det klart :D.

Sen så är det typ samma. kör ">roscore" i ny terminal för att start ros

I ny terminal i "root" kör ">source devel/setup.bash". och sedan kör ">rosrun ros publisher_node" för att köra vår publisher.

I ny terminal i "root" kör ">source devel/setup.bash". och sedan kör ">rosrun ros subscriber_node" för att köra vår subscriber.

För att se vilka typer av msgs en topic faktiskt skickar så kan vi köra i en terminal "rostopic info ros (min topic/pkg)"