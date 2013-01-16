#!/usr/bin/env ruby

(1..100).each do |x|
  str = ''
  str += 'Fizz' if x%3 == 0
  str += 'Buzz' if x%5 == 0
  if str.empty? then
    puts x
  else
    puts str
  end
end


# less readable, but it works:
#puts (1..100).map{ |x|
#  fizz = x%3 == 0 ? 'Fizz' : nil
#  buzz = x%5 == 0 ? 'Buzz' : nil
#  fizz || buzz ? "#{fizz}#{buzz}" : x
#}
