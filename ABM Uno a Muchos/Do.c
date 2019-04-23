/*1. Modificar las estructuras para poder trabajar con relaciones muchos a muchos.
2. Hardcodear datos para Empleados-Sectores (Interrelacion)
3. Modificar el alta de empleados, permitiendo seleccionar un sector.
4. Agregar una opcion al menu, para poder asociar un empleado en
particular a otro sector.
5. Resolver el calculo de sueldo bruto y neto. Teniendo en cuenta que si el
empleado trabaja en varios sectores el sueldo resultara de la suma del producto de las
 horas trabajadas por el valor hora de cada sector
*/

/**
1. Agregar la estructura sector, con idsector
2. En la estructura empleado, agregar un idsector
3. Hardcodear empleados con un sector
4. Modificar el alta para que el usuario seleccione un sector
5. Calcular el sueldo neto y bruto en funcion a las horas trabajadas y el valor por hora por sector

Nota: Tener en cuenta que si tenemos un abm de sectores, debe existir integridad referencial
entre los datos

Informar:

    a. Todos los empleados con la descripcion de su sector.
    b. Por cada sector, todos los empleados que en el trabajan.
    c. El total de sueldos por sector.
    d. El sector con mas empleados.

    por cada sector= for
    *recorrer sectores->info sector
    |->recorrer empleados
                |->info de empleados




 **/
