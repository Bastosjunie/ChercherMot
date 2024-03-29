using System;
using System.Collections.Generic;
using System.IO;

namespace WordFinder
{
    class Program
    {
        static void Main(string[] args)
        {
            // Chemin du fichier contenant le dictionnaire
            string dictionnairePath = "dictionnaire.txt";

            // Liste des mots fournis par l'utilisateur
            List<string> motsFournis = new List<string> { "omre", "teac", "tiodi", "ebor", "rion", "epuj", "cas", "eluih", "suj", "xsc" };

            // Charger le dictionnaire en mémoire
            HashSet<string> dictionnaire = ChargerDictionnaire(dictionnairePath);

            // Parcourir les mots fournis et trouver les correspondances
            foreach (string mot in motsFournis)
            {
                string correspondance = TrouverCorrespondance(mot, dictionnaire);
                Console.WriteLine($"{mot} : correspondant à {correspondance}");
            }

            Console.ReadLine();
        }

        static HashSet<string> ChargerDictionnaire(string path)
        {
            HashSet<string> dictionnaire = new HashSet<string>();

            try
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    string ligne;
                    while ((ligne = sr.ReadLine()) != null)
                    {
                        dictionnaire.Add(ligne);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"Erreur lors du chargement du dictionnaire : {e.Message}");
            }

            return dictionnaire;
        }

        static string TrouverCorrespondance(string mot, HashSet<string> dictionnaire)
        {
            char[] lettres = mot.ToCharArray();
            Array.Sort(lettres);
            string motTri = new string(lettres);

            foreach (string motDico in dictionnaire)
            {
                if (EstAnagramme(motDico, motTri))
                {
                    return motDico;
                }
            }

            return "aucune correspondance trouvée";
        }

        static bool EstAnagramme(string mot1, string mot2)
        {
            if (mot1.Length != mot2.Length)
            {
                return false;
            }

            char[] lettres1 = mot1.ToCharArray();
            char[] lettres2 = mot2.ToCharArray();

            Array.Sort(lettres1);
            Array.Sort(lettres2);

            string tri1 = new string(lettres1);
            string tri2 = new string(lettres2);

            return tri1.Equals(tri2);
        }
    }
