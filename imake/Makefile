# $NetBSD: Makefile,v 1.9 2003/07/25 19:10:37 blef Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	imake-${XF_VER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-3.tgz

MAINTAINER=	xfree86@xtraeme.unixbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Imake and other utilities from XFree86

USE_BUILDLINK2=	YES

INSTALL_TARGET=	install install.man

NO_XFREE86_TARGETS=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
.endif

post-extract:
.for F in ${SYSTEMS}
	@${MV} ${WRKSRC}/config/cf/${F}.cf \
		${WRKSRC}/config/cf/${F}.cf.in
.endfor
.undef F

pre-configure:
.for F in ${SYSTEMS}
	@${SED} -e "s|@@PKGSRC_CC@@|${CC}|g" \
		-e "s|@@PKGSRC_CPP@@|${CPP}|g" \
		-e "s|@@PKGSRC_CXX@@|${CXX}|g" \
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g" \
		${WRKSRC}/config/cf/${F}.cf.in > \
		${WRKSRC}/config/cf/${F}.cf
.endfor
.undef F

pre-build:
	@${TOUCH} ${WRKSRC}/config/cf/version.def
	@${TOUCH} ${WRKSRC}/config/cf/date.def
	@${CP} ${FILESDIR}/xf86site.def ${WRKSRC}/config/cf
	@${SED} \
		-e "s|PREFIX|${PREFIX}|g" \
		-e "s|BLNK|${BUILDLINK_DIR}|g" \
		-e "s|LOCALBASE|${LOCALBASE}|g " \
		-e "s|LDFLAGS|${LDFLAGS}|g" \
		${FILESDIR}/host.def > \
		${WRKSRC}/config/cf/host.def

do-build:
	( cd ${WRKSRC} && ${MAKE} Makefile.boot && \
	${MAKE} -f xmakefile VerifyOS version.def \
		Makefiles includes )

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
