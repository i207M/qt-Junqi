from PIL import Image, ImageOps
import glob


def add_border(img_file):
    image = Image.open(img_file)
    image = ImageOps.expand(image, border=15, fill=10040012)
    # image.show()
    image.save('border_' + file)


if __name__ == '__main__':
    for file in glob.glob('*.png'):
        add_border(file)
