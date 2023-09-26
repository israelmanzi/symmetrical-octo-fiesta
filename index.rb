# QueryParser w/ Ruby

# custom exception class
class CException < StandardError
    attr_reader :exception_type

    def initialize(msg="Custome error message", exception_type="CException")
        @exception_type = exception_type
        super(msg)
    end
end 

# :param _input: String
def parse_query(_input)
    # :return: Array
    output = _input.split("&")

    if output.empty?
        raise CException.new("Invalid input", "CException")
    end

    output.each do |item|
        if item.include?("=")
            item = item.split("=").map(&:strip)
            if item[0].empty?
                raise CException.new("Invalid input", "CException")
            end
        else
            raise CException.new("Invalid input", "CException")
        end

        if item[1].nil? or item[1].empty?
            item[1] = nil
        end

        puts "#{item[0]}: #{item[1]}"
    end

    output
end

begin
    parse_query("key1=value1&key2 =value2&key3=")
rescue CException => e
    puts e.message
    puts e.exception_type
end
