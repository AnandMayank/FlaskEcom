from intasend import APIService

API_PUBLISHABLE_KEY = 'ISPubKey_test_febc2e33-f8e2-4e40-ab85-6e2ba9e23df4'

API_TOKEN = 'ISSecretKey_test_ce4c3f46-1137-47e5-bf5e-b387897b3826'


service = APIService(token= API_TOKEN , publishable_key = API_PUBLISHABLE_KEY, test = True)

create_order = service.collect.mpesa_stk_push(phone_number='254879512138' , email='anandmayank698@gmail.com' , amount =100, narrative ='Purchase of items')

print(create_order)

