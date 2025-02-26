from flask_wtf import FlaskForm
from wtforms import StringField, IntegerField, FloatField, EmailField,BooleanField,PasswordField,SubmitField , SelectField
from wtforms.validators import Length, NumberRange ,DataRequired
from flask_wtf.file import FileField, FileRequired

class Signupform(FlaskForm):
    username = StringField(label='Username', validators=[ DataRequired(), Length(min=2)])
    email = EmailField(label='Email', validators=[DataRequired()])
    password1 = PasswordField(label='Enter your Password', validators=[ DataRequired(), Length(min=6)])
    password2 = PasswordField(label='Confirm your Password', validators=[ DataRequired(), Length(min=6)])
    submit = SubmitField(label='Sign Up')

class LoginForm(FlaskForm):
    email = EmailField(label='Email', validators=[DataRequired()])
    password = PasswordField(label='Enter your Password', validators=[DataRequired()])
    submit = SubmitField(label='Log in')


class PasswordChangeForm(FlaskForm):
    current_password = PasswordField(label='Current Password', validators=[DataRequired(), Length(min=6)])
    new_password = PasswordField(label='New Password', validators=[DataRequired(), Length(min=6)])
    confirm_new_password = PasswordField(label='Confirm Password', validators=[DataRequired(), Length(min=6)])
    change_password = SubmitField(label='Change Password')    


class ShopItemsForm(FlaskForm):
    product_name = StringField(label='Product Name', validators=[DataRequired()])
    current_price = FloatField(label='Current Price', validators=[DataRequired(), NumberRange(min=0)])
    previous_price = FloatField(label='Previous Price', validators=[DataRequired(), NumberRange(min=0)])
    in_stock = IntegerField(label='In Stock', validators=[DataRequired(), NumberRange(min=0)])
    product_picture = FileField(label='Product Picture', validators=[DataRequired()])
    flash_sale = BooleanField(label='Flash Sale')


    add_product = SubmitField(label='Add Product')
    update_product =SubmitField('Update Product')


class OrderForm(FlaskForm):
    order_status = SelectField('Order Status', choices=[('Pending', 'Pending'), ('Accepted', 'Accepted'),
                                                        ('Out for delivery', 'Out for delivery'),
                                                        ('Delivered', 'Delivered'), ('Canceled', 'Canceled')])

    update = SubmitField('Update Status')    

