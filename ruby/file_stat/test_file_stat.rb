#!/usr/bin/env ruby

require 'test/unit'
require './file_stat'

class TestFileStat < Test::Unit::TestCase

  File.open("temp.dat", "w") do |file|
    file.puts "123"
  end


  def test_file_stat_creation
    file_stat = FileStat.new("temp.dat")
    assert_not_equal(file_stat, nil)
  end
  
  def test_file_stat_total
    file_stat = FileStat.new("temp.dat")
    file_stat.read_file
    assert_equal(file_stat.total, 123);
  end

end

