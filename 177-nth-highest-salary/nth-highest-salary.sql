CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        select min(salary) from(
            select distinct salary 
            from Employee
            order by salary desc
            limit N
        ) as tenp
        having count(*) = N
  );
END