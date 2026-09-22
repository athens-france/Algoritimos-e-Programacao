import java.util.Scanner;

public class revisaoEstruturasDeDados {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); {

            String out = "";
            System.out.println("Insira valores inteiros espaçados: ");
            String[] numeros = sc.nextLine().split(" "); // retira os espaços vazios " " e separa os elementos individualmente
            System.out.println("Insira um valor inteiro para multiplicar os números informados:");
            int n = Integer.parseInt(sc.nextLine()); // transforma uma String em Int

            for (String valor : numeros) {
                int numero = Integer.parseInt(valor); // transforma o array de String em array de Int
                out += (numero * n) + " "; // multiplica os valores informados pelo valor inteiro informado
            }

            System.out.println("Resultado: \n"+out);
            System.out.println("Você digitou "+numeros.length+" números espaçados");

            /* Exemplo de soma de um número convertido de uma String para Int: 
            String texto = "60";
            int teste = Integer.parseInt(texto);
            System.out.println(teste + 7);
            */

            anomalias();

        }
        sc.close();
    }

    public static void anomalias() {
        int a = 100, b = 100;
        System.out.println("int 100 == int 100: " + (a == b)); // Números inteiros são primitivos, então a comparação é verdadeira se forem iguais
        Integer e = 200, f = 200;
        System.out.println("Integer 200 == Integer 200: " + (e == f)); // Aqui o Java cria dois novos objetos na memória e compara-os, então a comparação é falsa
        Integer g = 200, h = 200;
        System.out.println("Integer 200.equals(Integer 200): " + (g.equals(h))); // Usando o método equals() para comparar objetos ele compara os valores contidos nos objetos, e não os endereços de memória, então é verdadeira
    }
}