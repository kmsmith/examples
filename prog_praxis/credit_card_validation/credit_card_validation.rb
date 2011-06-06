#!/usr/bin/env ruby

# http://programmingpraxis.com/2011/04/08/credit-card-validation

def luhn_sum(num)
    x2 = [0, 2, 4, 6, 8, 1, 3, 5, 7, 9]
    #i = 0
    sum = 0
    num.to_s.reverse.chars.each_with_index do |x,i|
        sum = sum + ((i%2) > 0 ? x2[x.to_i] : x.to_i)
        #i = i + 1
    end
    sum
end

def is_valid_luhn(num)
    luhn_sum(num) % 10 == 0
end

def add_luhn_digit(num)
    if is_valid_luhn(num * 10)
        num * 10
    else
        (num * 10) + (10 - (luhn_sum(num * 10) % 10))
    end
end

test = 4992739871
puts luhn_sum(test)
puts "Testing #{test}"
puts "IsValid?  #{is_valid_luhn(test)}"
puts "Add Digit:  #{test = add_luhn_digit(test)}"
puts "Testing #{test}"
puts "IsValid?  #{is_valid_luhn(test)}"
