# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:_  
&nbsp; &nbsp; _(i) are common across several US/UC;_  
&nbsp; &nbsp; _(ii) are not tied to a single US/UC (e.g., Audit, Reporting, Security)._

- **Authentication & Authorization (RBAC):** roles *SNS User*, *Receptionist*, *Nurse*, *DGS Administrator*. Enforce least-privilege; only *Nurse* can access full clinical data.
- **Audit Trail:** record critical actions (scheduling, check-in, vaccination, reactions, certificates, catalog/center changes) with timestamp and actor ID.
- **Capacity Management:** validate **max vaccines/hour** per center/timeslot; prevent overbooking.
- **Notification:** appointment confirmations via external service (pluggable gateway); prepared for reminders.
- **Error Handling:** clear user-facing messages; structured error logs with correlation IDs.
- **Data Integrity & Validation:** field validation (unique IDs, formats, referential integrity: center, staff, vaccine types/brands).
- **Configuration:** *current outbreak* defines the **default vaccine type** offered during scheduling.
- **Reporting (MVP-light):** operational listings (e.g., daily agenda, queue, doses administered) exportable to text/CSV—lightweight scope in this phase.

## Usability

_Evaluates the user interface (error prevention, aesthetics/design, help/documentation, consistency/standards)._

- **CLI-first (MVP):** simple console UI with clear menus and explicit confirmation/error messages.
- **Error Prevention:** confirmations before destructive actions; immediate input validation (dates, SNS number, lot number).
- **Consistency & Standards:** naming conventions; date/time format ISO 8601; consistent lists and confirmations.
- **Future Accessibility:** when a GUI exists—readability (contrast/size), keyboard navigation; plain-language messages.
- **Help/Docs:** `--help` for commands and a README with usage examples.

## Reliability

_Integrity, compliance, and interoperability. Consider: failure frequency/severity, recovery, predictability, accuracy, MTBF._

- **Availability:** target **> 99%/year** for the core server.
- **Durability:** **no data loss** after confirmation (atomic transactions).
- **Recovery:** clean restart with no manual steps; idempotent reprocessing for notifications.
- **Accuracy:** timestamps in UTC; reliable clock (NTP).
- **MTBF/Errors:** logging levels (INFO/WARN/ERROR) and metrics to track failure frequency.

## Performance

_Response time, start-up, recovery time, memory/CPU usage, load capacity, availability._

- **Start-up:** cold start **< 10 s** on reference hardware.
- **Response Time:** core operations (schedule, check-in, record vaccination) **≤ 5 s** at p95 under peak load.
- **Throughput:** horizontal scaling of API service; buffering/queue for notification bursts.
- **Recovery Time:** service restart **≤ 10 s** with no loss of confirmed transactions.
- **Resource Usage:** moderate memory/CPU footprint; configurable pools/threads limits.

## Supportability

_Testability, adaptability, maintainability, compatibility, configurability, installability, scalability._

- **Testability:** unit and regression tests (e.g., GoogleTest); data fixtures; basic contract tests for notification client.
- **Observability:** metrics (latency, errors, per-slot capacity), health checks, structured logs.
- **Maintainability:** modular architecture (domain, services, REST/persistence/notification adapters).
- **Scalability:** persistence adapters for **in-memory**, **relational**, and **NoSQL**; multi-instance deployment.
- **Portability:** code and documentation in **English**; diagrams/images in **SVG**; simple CI on GitHub.

## +

### Design Constraints

_Specifies or constrains the system design process (languages, standards, tools, patterns)._

- **Language/Stack:** **C++ (server-side)**; CLion recommended.
- **Architecture:** *Layered/Hexagonal* with ports/adapters; HTTP API; clear separation between domain and infrastructure.
- **Documentation:** artifacts (UCD, Supplementary, API) in English; diagrams in **SVG**; single GitHub repository.
- **Process:** iterative development by sprints; explicit acceptance criteria for NFRs.

### Implementation Constraints

_Specifies or constrains code/construction (standards, languages, DB integrity, OS/resources)._

- **Authentication:** may be **mocked** for MVP; RBAC enforced at services.
- **Persistence:** repository abstraction; support relational (e.g., PostgreSQL), NoSQL (e.g., MongoDB), and **in-memory** for dev/test.
- **Migrations/Seed:** migrations for relational DB; seed reference data (vaccine technologies, diseases).
- **Quality:** build without critical warnings; consistent format/lint; tests in the pipeline.

### Interface Constraints

_Features inherent to interactions with external systems._

- **HTTP API:** REST endpoints for scheduling, check-in, queue, vaccination, reactions, certificates, and administration (centers, personnel, catalog, outbreak).
- **Notifications:** external gateway/client abstraction; timeouts, exponential retries, idempotency.
- **CLI:** standardized commands/parameters; human-friendly output.

### Physical Constraints

_Limitations/requirements regarding hardware housing the system (material, shape, size, weight)._

- **Reference Infra:** runs on standard Linux x64 server; no special hardware requirements.
- **Clock:** NTP synchronization to ensure temporal integrity of logs and events.
