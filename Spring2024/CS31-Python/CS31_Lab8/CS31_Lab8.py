
#     You will modify the Invoice program so that the program formats currency values correctly.
#     You will also add and calculate a shipping cost to the output. 
#     Review the code and run the program so that you understand the starting point. 
#     Modify the program so that it displays the order total and invoice total as U.S. currency values with dollar signs and two decimal points.
#     Add a shipping cost which should be 8.5% (.085) of the subtotal. Use the decimal module to make sure each monetary value has the correct number of decimal places. 
#     Be sure that your decimal places line up nice like in the example below.
#     Ensure that you have a title/greeting in your output. Be sure to have an exit message too. 
#     For the locale statement, you'll want to use something like:
        # locale.setlocale(locale.LC_ALL, ' ')  

# Example output:

# The Amazing Invoice program
# Enter order total: 10554.23

# Order total:       $10,554.23
# Discount amount:      2110.85
# Subtotal:             8443.38
# Shipping cost:         717.69
# Sales tax:             422.17
# Invoice total:      $9,583.24

# Continue? (y/n):

from decimal import Decimal
from decimal import ROUND_HALF_UP
import locale as lc

# display a title
print("The Invoice program")
print()

choice = "y"
while choice == "y":
    
    # get the user entry
    order_total = Decimal(input("Enter order total: "))
    order_total = order_total.quantize(Decimal("1.00"), ROUND_HALF_UP)
    print()               

    # determine the discount percent
    if order_total > 0 and order_total < 100:
        discount_percent = Decimal("0")
    elif order_total >= 100 and order_total < 250:
        discount_percent = Decimal(".1")
    elif order_total >= 250:
        discount_percent = Decimal(".2")

    # calculate the results
    discount = order_total * discount_percent
    discount = discount.quantize(Decimal("1.00"), ROUND_HALF_UP)                                
    subtotal = order_total - discount
    # add in shipping percent
    shipping_percent = Decimal("0.085")
    shipping_total = subtotal * shipping_percent;
    shipping_total = shipping_total.quantize(Decimal("1.00"), ROUND_HALF_UP)
    tax_percent = Decimal(".05")
    sales_tax = subtotal * tax_percent
    sales_tax = sales_tax.quantize(Decimal("1.00"), ROUND_HALF_UP)          
    # add shipping total to final invoice total
    invoice_total = subtotal + sales_tax + shipping_total


    lc.setlocale(lc.LC_ALL, 'en_US'); # for windows
    order_total = lc.currency(order_total, grouping = True)
    invoice_total = lc.currency(invoice_total, grouping = True)
    

    spec = "10," # format to 10 characters and put comas for thousands
    spec_currency = ">10" #show the currency symbol in front of our value
    spec_literal = 20

    # display the results
    print(f"{'Order total:':{spec_literal}}{order_total:{spec_currency}}")
    print(f"{'Discount amount:':{spec_literal}}{discount:{spec}}    ")
    print(f"{'Subtotal:':{spec_literal}}{subtotal:{spec}}")
    print(f"{'Shipping cost:':{spec_literal}}{subtotal:{spec}}")
    print(f"{'Sales Tax:':{spec_literal}}{subtotal:{spec}}")
    print(f"{'Invoice Total:':{spec_literal}}{invoice_total:{spec_currency}}")
    
    
    choice = input("Continue? (y/n): ")    
    print()
    
print("Bye!")

