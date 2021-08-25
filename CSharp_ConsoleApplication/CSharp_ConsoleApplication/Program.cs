using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_ConsoleApplication
{
    /// <summary>
    /// GaussMethod
    /// From: https://ru.wikipedia.org/wiki/Метод_Гаусса
    /// </summary>
    ///*
    class Program
    {
        static void Main(string[] args)
        {
            double[,] a = {
                          {1,-3,3,2,-4,4},
                          {3,-8,5,9,-13,-14},
                          {1,-1,-4,6,-4,-34},
                          {3,-4,-4,8,-4,-25},
                          {2,-5,5,2,-3,22}
                          };


            double[] result = GaussMethod(a);
            for (int i = 0; i < result.Length; i++)
            {
                Console.WriteLine("x["+i+"] = "+result[i]);
            }

            Console.ReadLine();
        }

        static double[] GaussMethod(double[,] a)
        {
            //найти размер матрицы
            int width = a.GetLength(1);
            int height = a.GetLength(0);
            WriteEquation(a);
            double[] x = new double[height]; //массив решений уравнения

            //инициализация массива корней уравнения
            for (int s = 0; s < x.Length; s++)
            {
                x[s] = a[s, width - 1];
            }
            //приведение матрицы к треугольному виду
            double m;
            for (int k = 0; k < width - 1; k++)
            {
                for (int j = k + 1; j < height; j++)
                {
                    m = a[j, k] / a[k, k];
                    for (int i = 0; i < height; i++)
                    {
                        a[j, i] -= m * a[k, i];
                    }
                    x[j] -= m * x[k];
                }
            }

            for (int i = 0; i < height; i++)
            {
                a[i, width - 1] = x[i];
            }
            Console.WriteLine("Приведение к треугольному виду");
            WriteEquation(a);

            for (int i = height - 1; i >= 0; i--)
            {
                for (int j = i + 1; j < width - 1; j++)
                {
                    x[i] -= i != j ? a[i, j] * x[j] : 0;
                }
                x[i] = x[i] / a[i, i];
            }

            return x;
        }

        static void WriteEquation(double[,] a)
        {
            int width = a.GetLength(1);
            int height = a.GetLength(0);

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width - 1; j++)
                {
                    Console.Write(a[i, j]+"x"+j+" ");
                }
                Console.Write("= "+a[i, width - 1]);
                Console.WriteLine();
            }
        }
    }
    //*/
}