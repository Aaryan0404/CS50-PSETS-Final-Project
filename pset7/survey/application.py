import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/register", methods=["POST"])
def post_form():
    if not request.form.get("firstname") or not request.form.get("secondname"):
        return render_template("error.html", message="Please provide your first and second names!")
    if not request.form.get("email"):
        return render_template("error.html", message="Please provide your email!")
    if not request.form.get("nationality"):
        return render_template("error.html", message="Please provide your nationality!")
    if not request.form.get("language"):
        return render_template("error.html", message="Please select your mother tongue!")
    if not request.form.get("colorabc"):
        return render_template("error.html", message="Please select your favorite color!")
    with open("survey.csv", "a") as file:
        writer = csv.DictWriter(file, fieldnames=["firstname", "secondname", "email", "nationality", "language", "color"])
        writer.writerow({"firstname": request.form.get("firstname"), "secondname": request.form.get("secondname"), "email": request.form.get("email"), "nationality": request.form.get("nationality"), "language": request.form.get("language"), "color": request.form.get("colorabc")})
    return redirect("/sheet")

@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as csvfile:
        reader = csv.DictReader(csvfile)
        entries = list(reader)
    return render_template("sheet.html", entries=entries)
