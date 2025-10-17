import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Locale;
import java.util.Map;

public class WordFrequency {
    public static Map<String, Integer> countWords(String input) {
        Map<String, Integer> frequency = new LinkedHashMap<>();
        Arrays.stream(input.toLowerCase(Locale.ROOT).split("\\W+"))
            .filter(token -> !token.isEmpty())
            .forEach(token -> frequency.merge(token, 1, Integer::sum));
        return frequency;
    }

    public static void main(String[] args) {
        String sample = "Log stream log metrics stream metrics log";
        Map<String, Integer> result = countWords(sample);
        result.forEach((word, count) -> System.out.printf("%s -> %d%n", word, count));
    }
}
