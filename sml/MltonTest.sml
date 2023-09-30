let
  val args = CommandLine.arguments ()
  val filename = hd args
in
  Test.read filename
end;
