
unsigned int    mylcm(unsigned int a, unsigned int b)
{
    int denominateur;

    if (a == 0 || b == 0)
        return (0);
    if (a > b)
        denominateur = b;
    else
        denominateur = a;
    while (1)
    {
        if (denominateur % a == 0 && denominateur % b == 0)
            return(denominateur);
        denominateur++;
    }
}