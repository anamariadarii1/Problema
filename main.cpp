#include "Familia.hpp"
bool comparare(int nr_sir_nume,const char* a,const char *sir_nume[])
{
    if(nr_sir_nume==0)
      return 0;
    for(int i = 0 ;i < nr_sir_nume; i++)
    {
        if(strcmp(a,sir_nume[i])==0)
           return 1;
    }
      return 0;
}

void sir_descrescator(const char *sir_nume[] ,int nr_aparitii[],int nr_sir_nume)
{
   int aux;
   const char *aux1;

    for(int i = 0; i < nr_sir_nume-1; i++)
		for(int j = i + 1; j < nr_sir_nume; j++)
        {
            if(nr_aparitii[i]<nr_aparitii[j])
            {
               aux = nr_aparitii[i];
				nr_aparitii[i] = nr_aparitii[j];
				nr_aparitii[j] = aux;
				aux1 = sir_nume[i];
				sir_nume[i] = sir_nume[j];
				sir_nume[j] = aux1;
            }
        }
}
int main()
{
    int n;
    cout << "Introduceti numarul de persoane: ";
    cin >> n;
    Familia *v;
    v = new Familia[n];
    for(int i = 0 ;i < n; i++)
        cin>> v[i];
    cout << endl;

    // sortam vectorului dupa varsta
    sort(v,v+n);

    //Populam vectorii sir_nume si nr_aparitii
   const char *sir_nume[4];//sir_nume este un vector care contine numele fiecarei persoane(daca un nume exista la mai multe persoane el apare in vector doar o singura data)
   int nr_sir_nume=0,nr_aparitii[4];//nr_sir_nume reprezinta numarul de elemente din vectorii sir_nume si nr_aparitii, nr_aparitii este vectorul ce contine numarul de aparitii a fiecarui nume

   for(int i = 0 ;i < n; i++)
   {
       if(comparare(nr_sir_nume,v[i].getNume(),sir_nume)==0)
       {
           sir_nume[i]=v[i].getNume();
           nr_aparitii[i]=1;
           nr_sir_nume=nr_sir_nume+1;
       }
       else
       {
         for(int j = 0 ;j < nr_sir_nume; j++)
         {
             if(strcmp(sir_nume[j],v[i].getNume())==0)
             {
                 nr_aparitii[j]++;
             }
         }
       }
   }

   //Sortam sir_nume descrescator dupa numarul de aparitii
    sir_descrescator(sir_nume,nr_aparitii,nr_sir_nume);

    //Verificam daca primul elementul din sir_nume apartine unei persoane ,daca da atunci afisam prenumele acelei persoane si dupa continuam sa verificum si urmatoarele elemente din sir_nume
    for(int j = 0 ;j < nr_sir_nume; j++)
    {
        cout << sir_nume[j]<<" : ";

            for(int i = 0 ;i < n; i++)
            {
                if((strcmp(sir_nume[j],v[i].getNume()))==0)
                    cout <<v[i].getPrenume()<<" ";
            }
            cout << endl;
    }

	delete []v;

    return 0;
}
