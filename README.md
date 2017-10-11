# LINQ_FOR_CPP

Add some feasures in C++ std containers that could be similar to LINQ in .net C#. 
It includes Where(), OrderBy(), OrderByDescending(), and Select() as wrapper function.

This is actually all about templating. It includes also template template(2 times templates, not a typo here) parameters. 

Where() is very similar to std::copy_if();
OrderBy() is very similar to std::sort();
Select() is ver similar to std::transform();
