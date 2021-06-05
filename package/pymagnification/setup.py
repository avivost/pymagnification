from setuptools import setup

with open('README.md', mode='r', encoding='utf-8') as fd:
    README_rst = fd.read()

setup(
    name='pymagnification',
    packages=['pymagnification'],
    version='0.0.2',
    license='MIT',
    description='Python wrapper to the windows magnification api',
    author='Aviv Ostrovsky',
    author_email='ostrovsky.aviv@gmail.com',
    url='https://github.com/avivost/pymagnification',
    download_url='https://github.com/avivost/pymagnification/archive/refs/tags/v0.0.2.zip',
    keywords=['winuse32', 'pywin32', 'python', 'UI', 'magnification', 'pymagnification'],
    install_requires=[],
    include_package_data=True,
    long_description=README_rst,
    long_description_content_type='text/markdown',
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Build Tools',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
    ],
)
