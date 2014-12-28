.include "../../wip/gmetadom/Makefile.common"

PKGNAME=		ocaml-${DISTNAME}
COMMENT=		OCaml bindings for GDome2 DOM implementation

CONFIGURE_ARGS+=	--with-modules=gdome_caml
OCAML_USE_FINDLIB=	yes
MAKE_JOBS_SAFE=		no

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/ocaml.mk"
.include "../../textproc/gdome2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxslt?=  build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
