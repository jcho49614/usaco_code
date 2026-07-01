import tensorflow as tf
import tensorflow.keras.losses as losses
import tensorflow.keras.Sequential as Sequential

mnist = tf.keras.datasets.mnist

(input_train, output_train), (input_test, output_test) = mnist.load_data()
input_train, input_test = input_train/255.0, input_test/255.0

model = tf.keras.models.Sequential([
	tf.keras.layers.Flatten(input_shape=(28,28)), 
	tf.keras.layers.Dense(128, activation='relu'),
	tf.keras.layers.Drop(0.2),
	tf.keras.layers.Dense(10)
	])

predictions = model(input_train[:1]).numpy()
tf.nn.softmax(predictions).numpy()

lossfunction = losses.SparseCategorialCrossentropy(from_logits=1)
lossfunction(output_train[:1], predictions).numpy()

model.compile(optimizer='adam',loss=lossfunction, metrics=['accuracy'])
model.fit(input_train, output_train, epochs=20)

model.evaluate(input_test, output_test, verbose=2)

probability_model = tf.keras.Sequential([
	model,
	tf.keras.layers.Softmax()
	])

probability_model(x_test[:5])