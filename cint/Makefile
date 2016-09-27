# $NetBSD: Makefile,v 1.31 2015/12/11 23:32:53 joerg Exp $

DISTNAME=		cint-5.16.19-source
PKGNAME=		${DISTNAME:S/-source//}
CATEGORIES=		lang
MASTER_SITES=		https://root.cern.ch/download/

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.hanno.jp/gotom/Cint.html
COMMENT=		C/C++ interpreter

USE_TOOLS+=		bash gmake pax
USE_LANGUAGES=		c c++

CONFIG_SHELL=		${BASH}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--arch=netbsd
# For some reason I cannot get BUILDLINK path for .readline
CONFIGURE_ARGS+=	--readline=${PREFIX}/lib/libreadline.so

USE_LANGUAGES=		c c++

HAS_CONFIGURE=			yes
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
# It does not work
CPPFLAGS+=			-Wno-write-strings
# For some reason I cannot get BUILDLINK path for .readline
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/cint/lib

BUILD_TARGET=			# empty string required

INSTALLATION_DIRS+=	bin cint cint/lib share/doc/cint
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man2 ${PKGMANDIR}/man3

post-extract:
	${FIND} ${WRKSRC} -depth -type d -name CVS -exec ${RM} -rf {} \;
	${FIND} ${WRKSRC} -type f -name .cvsignore -exec ${RM} -f {} \;

# We do not want these files to be installed
pre-install:
	${RM} -f ${WRKSRC}/include/Makeit
	${RM} -f ${WRKSRC}/include/make*

do-install:
.for _file_ in cint makecint # inc/G__ci.h
	${INSTALL_PROGRAM} ${WRKSRC}/${_file_} ${DESTDIR}${PREFIX}/cint
.endfor
	${INSTALL_DATA} ${WRKSRC}/inc/G__ci.h ${DESTDIR}${PREFIX}/cint
	${INSTALL_PROGRAM} ${WRKSRC}/libcint.so ${DESTDIR}${PREFIX}/cint/lib
	${SED} "s;XXXPREFIXXXX;${PREFIX};g" <${FILESDIR}/cint.sh \
		>${DESTDIR}${PREFIX}/bin/cint
	${RUN} cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf cint makecint
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/cint
	${RUN} cd ${WRKSRC} && ${PAX} -rw include stl ${DESTDIR}${PREFIX}/cint
	${RUN} cd ${WRKSRC}/lib && ${PAX} -rw prec_stl ${DESTDIR}${PREFIX}/cint/lib
.for _file_ in bytecode.txt cint.txt cintapi.txt extlib.txt ifdef.txt limitati.txt limitnum.txt makecint.txt message.txt ref.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${_file_} \
		${DESTDIR}${PREFIX}/share/doc/cint
.endfor
.for _file_ in cint.1 makecint.1 garbage.2 security.2 unique.2 array.h.3 fft.h.3 statistics.h.3
	${INSTALL_MAN} ${WRKSRC}/doc/man${_file_:E}/${_file_} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man${_file_:E}
.endfor

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
