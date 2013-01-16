#!/usr/bin/env ruby

# useful as a first step in cryptanalysis
# usage:
#   ./freq_count.rb < cipher.txt

freqs = Hash.new {|hash, key| hash[key] = 0 }
num_chars = 0

while line = gets
    puts line.upcase
    line.chomp.chars {|char| freqs[char] = freqs[char] + 1 }
    num_chars = num_chars + line.size
end

puts "Found #{num_chars} total characters"
puts "Found #{freqs.keys.count} unique characters"

freqs.keys.sort.each {|char|
  puts "#{char}:  #{freqs[char]} (#{(freqs[char]*100)/num_chars}%)"
}
