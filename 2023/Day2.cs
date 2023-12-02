using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace _2023
{
    public class Day2
    {
        public static long Part1(string filepath)
        {
            int maxRed = 12, maxGreen = 13, maxBlue = 14;
            long sumOfIds = 0;
            foreach (var line in File.ReadAllLines(filepath))
            {
                bool gameIsPossible = true;
                foreach (var gameSet in Regex.Match(line, @"(?<=:\s).*").Value.Split(";"))
                {
                    foreach (var cubes in gameSet.Split(","))
                    {
                        if (cubes.Contains("red") && Int32.Parse(Regex.Match(cubes, @"\d+").Value) > maxRed
                            || cubes.Contains("green") && Int32.Parse(Regex.Match(cubes, @"\d+").Value) > maxGreen
                            || cubes.Contains("blue") && Int32.Parse(Regex.Match(cubes, @"\d+").Value) > maxBlue)
                        {
                            gameIsPossible = false;
                            break;
                        }
                    }
                }
                sumOfIds += gameIsPossible ? Int32.Parse(Regex.Match(line, @"\d+(?=:)").Value) : 0;
            }
            return sumOfIds;
        }

        public static long Part2(string filepath)
        {
            long sum = 0;
            foreach (var line in File.ReadAllLines(filepath))
            {
                int maxRed = 0, maxGreen = 0, maxBlue = 0;
                foreach (var gameSet in Regex.Match(line, @"(?<=:\s).*").Value.Split(";"))
                {
                    foreach (var cubes in gameSet.Split(","))
                    {
                        int num = Int32.Parse(Regex.Match(cubes, @"\d+").Value);
                        maxRed = (cubes.Contains("red") && num > maxRed) ? num : maxRed;
                        maxGreen = (cubes.Contains("green") && num > maxGreen) ? num : maxGreen;
                        maxBlue = (cubes.Contains("blue") && num > maxBlue) ? num : maxBlue;
                    }
                }
                sum += maxRed * maxGreen * maxBlue;
            }
            return sum;
        }
    }
}