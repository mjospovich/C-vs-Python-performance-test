import time
import psutil


def measure_time_and_memory(function, repetitions=100):
    """Measures the time and memory used by the function provided as a parameter."""
    
    process = psutil.Process()  # Get current process
    
    start_time = time.perf_counter() # Get the start time
    start_memory = process.memory_full_info().rss # Get the start memory

    for _ in range(repetitions):
        function() # Call the function 'repetitions' times

    end_time = time.perf_counter() # Get the end time
    end_memory = process.memory_full_info().rss # Get the end memory

    time_taken = (end_time - start_time) * 1000 / repetitions # Convert time to milliseconds per repetition
    memory_used = (end_memory - start_memory) / 1000 / repetitions  # Convert memory to bytes per repetition

    return time_taken, memory_used # Return the time and memory used


def print_time_and_memory(function, repetitions=3):
    """Prints the time and memory used by the function provided as a parameter."""
    
    time, mem = measure_time_and_memory(function, repetitions)
    print(f"Time taken: {time} ms")
    print(f"Memory used: {mem} KB")