# $NetBSD: Makefile,v 1.6 2005/03/24 21:13:27 thomasklausner Exp $

DISTNAME=	emacs-carbon-21.3.50
CATEGORIES=	editors
MASTER_SITES=	http://qwosh.at.infoseek.co.jp/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU Emacs with Aqua user interface

BUILD_DEPENDS+=	gtexinfo>=4.6:../../devel/gtexinfo

ONLY_FOR_PLATFORM=	Darwin-*-*

CONFLICTS=	mule-[0-9]*

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-carbon
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}

MAKE_ENV+=	"MAKEINFO=${LOCALBASE}/bin/makeinfo"

.include "../../graphics/xpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xpm
.include "../../graphics/jpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gif
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	--with-png

.include "../../mk/bsd.prefs.mk"

INFO_FILES=	ada-mode autotype ccmode cl dired-x ebrowse ediff efaq emacs
INFO_FILES+=	emacs-mime eshell eudc forms gnus idlwave message mh-e pcl-cvs
INFO_FILES+=	reftex sc speedbar vip viper widget woman

REPLACE_PERL=	lib-src/grep-changelog

BUILD_TARGET=	bootstrap

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs
	(cd ${WRKSRC}/mac;${PAX} -rw Emacs.app ${PREFIX}/bin)

.include "../../mk/bsd.pkg.mk"
