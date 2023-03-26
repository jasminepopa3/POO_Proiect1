# POO_Proiect1

Mă numesc Popa Jasmine Mihaela, iar tema pe care am ales-o pentru proiectul la materia Programare Orientată pe Obiecte este gestiunea unui muzeu.
Am implementat 6 clase diferite: Perioada, Curent_artistic, Artist, Exponat, Expozitie, Angajat. Clasele Perioada, Curent_artistic și Artist sunt utilizate ca tip de date în alte clase, astfel având clase corelate prin compunere.
Clasa Perioada definește doua date de tip char prin care precizez data la care începe și data la care se sfârșește o acțiune relevantă (desfașurarea unui curent artistic, viața unui pictor etc.). 
Am decis să creez această clasă Perioada, deoarece în multe dintre celelalte clase am avut nevoie de acest tip de informație.
Clasa Curent_artistic definește o dată de tip char prin care ofer o denumire unui curent artistic, dar și o dată de tip Perioada prin care numesc perioada în care s-a manifestat acel curent.
Clasa Artist prezintă mai multe detalii despre un anumit artist (nume, prenume, perioada vietii, curentul artistic la care a aderat etc).
Clasa Exponat prezintă picturile/statuile care apar la diverse expozitii. Aici am implementat metoda bool exponate_dupa1900() prin care verific câte dintre exponatele numite au fost create după anul 1900.
Clasa Expozitie prezintă mai multe detalii despre o anumită expoziție, dintre care și o listă cu toți artiștii care au lucrări expuse în aceasta. Prin urmare, am considerat relevant să implementez o altă metodă, void detalii_Artisti(), care să prezinte detalii despre artiștii care au lucrări expuse.
În scrierea acestui cod, am utilizat mai mulți constructori cu și fără parametrii în diverse clase, alături de setteri și getteri care să mă ajute să extrag datele necesare, respectând principiul encapsulării.
Am explicitat citirile de la tastatură și afișările pe ecran pentru fiecare clasă.
