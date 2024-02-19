import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import classification_report

data = pd.read_csv("news.csv")

data['document'] = data['title'] + data['text']

trainingDocs, testDocs, trainingClasses, testClasses = train_test_split(data['document'], data['label'], test_size=0.3, random_state=42)

vectorizer = TfidfVectorizer()
vecTrainingDocs = vectorizer.fit_transform(trainingDocs)
vecTestDocs = vectorizer.transform(testDocs)

naive_bayes = MultinomialNB()
naive_bayes.fit(vecTrainingDocs, trainingClasses)

predictions = naive_bayes.predict(vecTestDocs)

print("Classification Report:")
print(classification_report(testClasses, predictions))


