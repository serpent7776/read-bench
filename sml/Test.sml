structure Test = struct

fun read (filename) =
  let
    val file = TextIO.openIn filename
    val str = TextIO.inputAll file
    val len = size str
  in
    print (Int.toString len)
  end

end
