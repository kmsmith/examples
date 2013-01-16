
if ARGV[0] != nil then
  file_stat = FileStat.new(ARGV[0])
  begin
    file_stat.read_file

    puts "\nNumbers:"
    file_stat.print_nums

    puts "\nTotal:"
    puts file_stat.total

    puts "\nAverage:"
    puts file_stat.average

    puts "\nMax:"
    puts file_stat.max

    puts "\nMin:"
    puts file_stat.min
  rescue Exception
    STDERR.puts "Failed to process #{ARGV[0]}:"
    STDERR.puts "  #{$!}"
  end
else
  puts "Usage:  #{$0} filename"
end
