# $NetBSD: Makefile,v 1.3 2012/10/07 14:22:05 asau Exp $
#

DISTNAME=	ripit-3.6.0
CATEGORIES=	audio
MASTER_SITES=	http://www.suwald.com/ripit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.suwald.com/ripit/
COMMENT=	Perl-script frontend for encoding audio CDs to OGG/MP3 files

NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	${WRKSRC}/ripit.pl

DEPENDS=	p5-CDDB_get>=0:../../audio/p5-CDDB_get
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=	cdparanoia>=0:../../audio/cdparanoia
DEPENDS+=	vorbis-tools>=0:../../audio/vorbis-tools
#DEPENDS+=	lame>=0:../../audio/lame
#DEPENDS+=	flac>=0:../../audio/flac
#DEPENDS+=	faac>=0:../../audio/faac



.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
RAWPART_cmd=		/sbin/sysctl -n kern.rawpartition | ${TR} 0-9 a-j
SUBST_CLASSES+=		fix-dev
SUBST_STAGE.fix-dev=	do-configure
SUBST_FILES.fix-dev=	ripit.pl ripit.1
SUBST_SED.fix-dev=	-e 's,/dev/cdrom,/dev/rcd0${RAWPART_cmd:sh},g'
.endif

do-configure:
	${MV} ${WRKSRC}/ripit.pl ${WRKSRC}/ripit.pl.dist
	${SED} -e 's,my @coder.*;,my @coder= \(1\);,1' ${WRKSRC}/ripit.pl.dist > ${WRKSRC}/ripit.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${DESTDIR}${PREFIX}/bin/ripit
	${INSTALL_MAN} ${WRKSRC}/ripit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/ripit
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/ripit

.include "../../mk/bsd.pkg.mk"
