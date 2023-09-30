structure Smlnj = struct

fun main (_, args) =
  let
    val second = hd o tl
    val filename  = second args
  in
    Test.read filename;
    OS.Process.exit OS.Process.success
  end

end
