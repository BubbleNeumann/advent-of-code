using System.Text.RegularExpressions;

namespace _2023
{
    public class Day1
    {
        public static long Part1(string filename)
        {
            long sum = 0;
            foreach (var e in File.ReadAllLines(filename))
            {
                sum += Int32.Parse(Regex.Match(e, @"\d").Value) * 10;
                var s = e.ToCharArray();
                Array.Reverse(s);
                sum += Int32.Parse(Regex.Match(new string(s), @"\d").Value);
            }
            return sum;
        }

        public static long Part2(string filename)
        {
            long sum = 0;
            List<string> letterDigits = new(new string[]
            {
                "one",
                "two",
                "three",
                "four",
                "five",
                "six",
                "seven",
                "eight",
                "nine",
            });
            foreach (var e in File.ReadAllLines(filename))
            {
                var minLetterDigitPos = Int32.MaxValue;
                var maxLetterDigitPos = -1;
                int firstLetterDigit = -1, lastLetterDigit = -1;
                foreach (var letterDigit in letterDigits)
                {
                    var ind = e.IndexOf(letterDigit);
                    if (ind != -1 && ind < minLetterDigitPos)
                    {
                        minLetterDigitPos = ind;
                        firstLetterDigit = letterDigits.IndexOf(letterDigit) + 1;

                    }
                    ind = e.LastIndexOf(letterDigit);
                    if (ind > maxLetterDigitPos)
                    {
                        maxLetterDigitPos = ind;
                        lastLetterDigit = letterDigits.IndexOf(letterDigit) + 1;
                    }
                }

                var firstDigit = Regex.Match(e, @"\d");
                var s = e.ToCharArray();
                Array.Reverse(s);
                var lastDigit = Regex.Match(new string(s), @"\d");
                sum += ((firstDigit.Success && (firstDigit.Index < minLetterDigitPos || firstLetterDigit == -1)) ? Int32.Parse(firstDigit.Value) : firstLetterDigit) * 10 + 
                       ((lastDigit.Success && ((e.Length- lastDigit.Index -1) > maxLetterDigitPos || lastLetterDigit == -1)) ? Int32.Parse(lastDigit.Value) : lastLetterDigit);
            }

            return sum;
        }
    }
}