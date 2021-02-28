  
FROM python:3
ADD fib_script.py .
CMD [ "python", "./fibonacci.py" ]