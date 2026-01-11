
| TEA (EN) | TEA (PT) | Description (EN) |
| :--- | :--- | :--- |
| **Adverse Reaction** | Reação adversa | [cite_start]Any negative response observed after a vaccine is administered, recorded by the nurse with details such as severity, description, and notes.[cite: 61][cite_end] |
| **API** | API | [cite_start]Acronym for *Application Programming Interface*. The server-side application exposes multiple APIs to support user applications.[cite: 97, 100][cite_end] |
| **Appointment** | Marcação | [cite_start]A scheduled vaccination slot chosen by an SNS user, including date, time, vaccine type, and vaccination center, subject to capacity checks and confirmation.[cite: 29, 43][cite_end] |
| **Capacity Check** | Verificação de capacidade | [cite_start]Business rule that validates whether a vaccination center has available capacity for a given timeslot, based on its maximum vaccines per hour.[cite: 29, 32][cite_end] |
| **Community Mass Vaccination Center** | Centro de vacinação em massa comunitário | [cite_start]Temporary facilities established specifically to administer a single type of vaccine during an ongoing disease outbreak.[cite: 33][cite_end] |
| **DGS** | DGS | [cite_start]Acronym for the Portuguese state-funded healthcare authority responsible for the National Vaccination Program.[cite: 7, 17, 28][cite_end] |
| **DGS Administrator** | Administrador(a) da DGS | [cite_start]Personnel responsible for managing the application, including the registration of vaccination centers and personnel, and configuring core data such as vaccines and outbreaks.[cite: 62, 63][cite_end] |
| **Healthcare Center** | Centro de saúde | [cite_start]Facilities that provide a wide range of medical services to citizens and can administer various types of vaccines.[cite: 32][cite_end] |
| **Nurse** | Enfermeiro(a) | [cite_start]Personnel authorized to access users’ full health data, view the waiting queue, administer vaccines, record vaccination events, and log any adverse reactions.[cite: 54, 57, 58, 61][cite_end] |
| **Notification Service** | Serviço de notificação | [cite_start]External service responsible for sending appointment confirmations and reminders to users after successful scheduling.[cite: 29][cite_end] |
| **Outbreak** | Surto | [cite_start]Disease outbreak context for which the system suggests a default vaccine type during appointment scheduling.[cite: 29][cite_end] |
| **PVMS** | PVMS | [cite_start]Acronym for *Pandemic Vaccination Management System*, the software product developed to manage the vaccination process in Portugal.[cite: 94][cite_end] |
| **Receptionist** | Rececionista | [cite_start]Personnel who register an SNS user’s arrival, verify appointments, mark users as ready in the system, and may assist with in-person appointment scheduling.[cite: 48, 52, 53][cite_end] |
| **SNS User** | Utente do SNS | [cite_start]A user of the National Health Service who can register, schedule vaccination appointments, and obtain vaccination certificates through the application.[cite: 29, 30, 43][cite_end] |
| **UI** | IU (Interface de Utilizador) | [cite_start]Acronym for *User Interface*. The system envisions multiple UIs, including a web application for DGS staff, a mobile app for SNS users, and a console-based UI for demonstration purposes.[cite: 68, 70, 72][cite_end] |
| **Vaccine** | Vacina / Marca | [cite_start]A concrete vaccine brand (e.g., Pfizer, Moderna) associated with a vaccine type; includes commercial name, brand, and technology used.[cite: 63][cite_end] |
| **Vaccine Type** | Tipo de vacina | [cite_start]Core classification of a vaccine (e.g., Covid-19, Influenza), defined by code, disease, and a short description.[cite: 63][cite_end] |
| **Vaccination Certificate** | Certificado de vacinação | [cite_start]Official document proving a vaccination event; can be issued on-site at healthcare centers upon user request.[cite: 29, 32][cite_end] |
| **Vaccination Event** | Evento de vacinação | [cite_start]The record that captures the administration of a vaccine, including date/time, vaccine type, brand, and lot number, and may reference adverse reactions.[cite: 58, 61][cite_end] |
| **SNS Number** | Número de Utente do SNS | A unique 9-digit identification number required to register an SNS user in the system and to validate their identity during appointment scheduling.[cite_end] |
| **Vaccine Schedule** | Agendamento de Vacina | The domain entity created when a receptionist or user successfully registers a vaccination slot, linking an SNS User to a specific date, time, center, and vaccine type.[cite_end] |
| **Slot Availability** | Disponibilidade de vaga | The real-time status of a vaccination center's capacity, calculated by comparing existing schedules against the maximum vaccines per hour limit.[cite_end] |
| **SNS User Registration** | Registo de utente do SNS | The process of adding a new citizen to the system (US20), involving the collection of personal data such as name, address, sex, contact details, and the unique SNS number.[cite_end] |
| **Schedule Confirmation** | Confirmação de agendamento | The final step of the scheduling process where the receptionist validates the summary of entered data and persists the record in the system.[cite_end] |
| **Waiting Room** | Sala de espera | A virtual or physical area where an SNS user is assigned by the receptionist upon arrival, prior to vaccine administration by a nurse.[cite_end] |
| **Recovery Room** | Sala de recuperação | The area where the SNS user is assigned after vaccine administration to be monitored for any immediate adverse reactions.[cite_end] |
