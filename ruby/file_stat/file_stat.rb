class FileStat

  def initialize(file_name)
    @file_name = file_name
    @nums = []
  end

  def read_file
    File.open(@file_name) do |file|
      file.each_line { |line| @nums << line.chomp.to_f }
    end
  end

  def print_nums
    @nums.each { |x| puts x }
  end

  def total
    @nums.reduce { |sum, x| sum = sum+x }
  end

  def average
    total / @nums.size
  end

  def max
    @nums.max
  end

  def min
    @nums.min
  end

  def to_s
    "Reader for #{@file_name}"
  end
end
