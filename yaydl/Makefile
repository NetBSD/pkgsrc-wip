# $NetBSD: Makefile,v 1.1.1.1 2010/07/27 21:43:24 ryo-on Exp $
#

DISTNAME=	yaydl-1.5.2
CATEGORIES=	net
MASTER_SITES=	http://pdes-net.org/x-haui/scripts/perl/yaydl_youtubedownloader/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://pdes-net.org/x-haui/scripts/perl/yaydl_youtubedownloader/
COMMENT=	Yet another youtube downloader written in perl
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=	p5-Getopt-Long>=2.38:../../devel/p5-Getopt-Long
DEPENDS+=	p5-LWP-UserAgent-Determined>=1.04:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=	p5-MP3-Info>=1.24:../../audio/p5-MP3-Info
DEPENDS+=	p5-Term-ProgressBar>=2.09nb2:../../devel/p5-Term-ProgressBar
DEPENDS+=	ffmpeg>=20090611nb8:../../multimedia/ffmpeg

INSTALLATION_DIRS=	bin share/doc/yaydl.pl

USE_LANGUAGES=	# none

USE_TOOLS+=	perl

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing pathes
SUBST_FILES.fix-paths=		install
SUBST_SED.fix-paths=		-e 's,`which perl`,${PERL5},g'
SUBST_SED.fix-paths+=		-e 's,yaydl.pl,${WRKSRC}/yaydl.pl,g'
SUBST_SED.fix-paths+=		-e 's,/usr/local/bin,${DESTDIR}${PREFIX}/bin,g'
SUBST_SED.fix-paths+=		-e 's,./modtest.pl,modtest.pl,g'
SUBST_SED.fix-paths+=		-e 's,modtest.pl,${WRKSRC}/modtest.pl,g'
SUBST_SED.fix-paths+=		-e 's,./adjust.pl,adjust.pl,g'
SUBST_SED.fix-paths+=		-e 's,adjust.pl,${WRKSRC}/adjust.pl,g'

NO_BUILD=	yes
REPLACE_PERL=	yaydl.pl

do-install:
	${WRKSRC}/install
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/changelog ${DESTDIR}${PREFIX}/share/doc/yaydl.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
