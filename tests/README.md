
# Unit Converter Test Suite

This test suite helps you verify that your implementations are working correctly. Each test checks specific functionality of the methods you need to implement.

## How to Run Tests

1. **Navigate to the tests directory:**
   ```bash
   cd tests
   ```

2. **Compile and run the tests:**
   ```bash
   make run
   ```

3. **Or compile and run separately:**
   ```bash
   make
   ./test_runner
   ```

## Test Categories

### 1. Unit Class Tests
- Constructor and getter methods
- `toBase()` and `fromBase()` conversion methods
- Tests with different conversion factors

### 2. UnitCategory Class Tests
- Constructor with base unit creation
- `addUnit()` method functionality
- `findUnit()` method (including null cases)
- `getUnitNames()` method

### 3. Converter Class Tests
- Basic `convert()` method between units
- Temperature conversion methods:
  - `celsiusToFahrenheit()` and `fahrenheitToCelsius()`
  - `celsiusToKelvin()` and `kelvinToCelsius()`
- Complex temperature conversions with `convertTemperature()`

### 4. UnitRegistry Class Tests
- Default category initialization
- `findCategory()` method
- `getCategoryNames()` method
- `canAddUnitsToCategory()` method
- `addUnitToCategory()` method

### 5. Validation Class Tests
- `isValidDouble()` with various number formats
- `isValidInt()` for integer validation
- `isValidUnitName()` for valid unit names
- `trim()` for whitespace removal
- `toLowerCase()` for case conversion

## Expected Test Results

- **Unit Class:** 10 tests covering basic functionality
- **UnitCategory Class:** 10 tests covering category management
- **Converter Class:** 15 tests covering all conversion types
- **UnitRegistry Class:** 12 tests covering registry operations
- **Validation Class:** 20 tests covering input validation

**Total: 67 tests**

## Implementation Tips

1. **Start with Unit class** - It's the foundation for everything else
2. **Then UnitCategory** - Builds on Unit functionality
3. **Work on Validation** - Helps with input handling in other classes
4. **Implement UnitRegistry** - Manages the overall system
5. **Finish with Converter** - Uses all other components

## Common Test Failures

- **Null pointer returns:** Make sure methods return `nullptr` when items aren't found
- **Conversion factor errors:** Remember base units have factor 1.0
- **Temperature conversions:** Use the exact formulas provided in comments
- **String validation:** Pay attention to allowed characters and patterns

## Running Individual Test Categories

You can modify the `main()` function in `TestRunner.cpp` to run specific test categories:

```cpp
int main() {
    TestRunner testRunner;
    // Run only specific tests:
    testRunner.testUnitClass();
    // testRunner.testUnitCategoryClass();
    // ... etc
    return 0;
}
```

Good luck with your implementation!
