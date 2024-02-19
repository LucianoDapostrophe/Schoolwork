import nltk
import csv
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer, PorterStemmer

def tokenize(text):
    return word_tokenize(text)

def remove_stopwords(tokens):
    stop_words = set(stopwords.words('english'))
    return [token for token in tokens if token.lower() not in stop_words]

def lemmatize(tokens):
    lemmatizer = WordNetLemmatizer()
    return [lemmatizer.lemmatize(token) for token in tokens]

def stem(tokens):
    stemmer = PorterStemmer()
    return [stemmer.stem(token) for token in tokens]

def assemble_token_dict(tokens):
    word_count = {}
    for token in tokens:
        word_count[token] = word_count.get(token, 0) + 1
    return word_count

def parse_csv(filename):
    with open(filename, 'r', newline='', encoding='utf-8') as csvfile:
        reader = csv.reader(csvfile)
        all_text = ' '.join(row[1] for row in reader)
        return all_text

filename = "news.csv"
text = parse_csv(filename)
tokens = tokenize(text)

print("\nTotals with stopwords:")
print(str(len(assemble_token_dict(tokens))) + " word types")
print(str(sum(assemble_token_dict(tokens).values())) + " total tokens")

tokens_without_stopwords = remove_stopwords(tokens)
print("\nTotals without stopwords:")
print(str(len(assemble_token_dict(tokens_without_stopwords))) + " word types excluding stopwords")
print(str(sum(assemble_token_dict(tokens_without_stopwords).values())) + " total tokens without stopwords")

tokens_lemmatized = lemmatize(tokens_without_stopwords)
print("\nTotals with no stopwords and with lemmatization:")
print(str(len(assemble_token_dict(tokens_lemmatized))) + " lemmatized word types")
print(str(sum(assemble_token_dict(tokens_lemmatized).values())) + " total tokens with lemmatization")

tokens_stemmed = stem(tokens_without_stopwords)
print("\nTotals with no stopwords and with stemming:")
print(str(len(assemble_token_dict(tokens_stemmed))) + " stemmed word types")
print(str(sum(assemble_token_dict(tokens_stemmed).values())) + " total tokens with stemming\n")