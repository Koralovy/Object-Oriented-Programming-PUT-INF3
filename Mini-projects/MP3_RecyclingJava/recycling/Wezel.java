package recycling;
import java.util.*;

public class Wezel {
    @Deprecated
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    protected ArrayList<Wezel> polaczenia = new ArrayList<>();
    protected HashMap<Wezel, Boolean> polaczenia2 = new HashMap<>();

    TreeMap<Wezel,Boolean> polaczenia3 = new TreeMap<>(new Comparator<Wezel>()
    {
        public int compare(Wezel o1, Wezel o2)
        {
            if(o1.hashCode() > o2.hashCode())
                return 1;
            else
                return -1;
        }
    });

    public void dodajPolaczenie(Wezel w) {
        this.polaczenia.add(w);
    } 

    public void dodajPolaczenie2(Wezel w, boolean b) {
        this.polaczenia2.put(w, b);
    }

    public void dodajPolaczenie3(Wezel w, boolean b) {
        this.polaczenia3.put(w, b);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for (int i = 0; i <+ 1000000; i++) {
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            w1.dodajPolaczenie(w2);
            w1.dodajPolaczenie2(w2, true);
            w1.dodajPolaczenie3(w2, true);
            w2.dodajPolaczenie(w1);
            w2.dodajPolaczenie2(w1, true);
            w2.dodajPolaczenie3(w1, true);

        }
        s.nextLine();
        s.close();
    }


    //Zad 5: Nie, nie zostal
    //Zad 6: garbagecollector dziala niedeterministycznie, wiec wywoluje sie w losowych momentach oczyszczajc pamiec
    //Zad 11: wskazniki bez dostepu dla programu zostaja usuniete, poniewaz nie zostana nigdy wykorzystane
    //Zad 12: tradycyjna tablica w porownaniu do deklaracji generycznej nie bedzie zawierac licznych wbudowanych w jezyk optymalizacji i moze zmniejszyc uzytecznosc garbage collectora


}

