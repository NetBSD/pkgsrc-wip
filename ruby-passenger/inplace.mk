# $NetBSD: inplace.mk,v 1.2 2013/09/05 10:55:51 fhajny Exp $

USE_LANGUAGES+=		c c++
USE_RAKE=		yes

MAKE_ENV+=		EXTRA_LDFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_ENV+=		USE_VENDORED_LIBEIO=no
MAKE_ENV+=		USE_VENDORED_LIBEV=no

post-extract: extract-inplace-passenger

extract-inplace-passenger:
	cd ../../wip/ruby-passenger && ${MAKE} WRKDIR=${WRKDIR}/.passenger EXTRACT_DIR=${WRKDIR} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES fetch patch clean
	${LN} -s ${WRKDIR}/passenger-* ${WRKDIR}/passenger

BUILDLINK_DEPMETHOD.curl=	build
BUILDLINK_DEPMETHOD.libeio=	build
BUILDLINK_DEPMETHOD.libev=	build

.include "../../wip/libeio/buildlink3.mk"
BUILDLINK_API_DEPENDS.libev+=	libev>=4.11
.include "../../devel/libev/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../www/curl/buildlink3.mk"
