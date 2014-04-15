# This file provides common targets for ocaml libraries made with oasis.

.if !defined(_OCAML_OASIS_MK)
_OCAML_OASIS_MK= # defined

.include "../../mk/bsd.prefs.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"

USE_LANGUAGES=  c
HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix "${PREFIX}" --destdir "${DESTDIR}"

PLIST_VARS+=    opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=      yes
.endif

do-configure:
	cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ocaml setup.ml -build

pre-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.endif  # OCAML_OASIS
