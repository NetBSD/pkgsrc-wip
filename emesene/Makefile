# $NetBSD: Makefile,v 1.1 2012/12/26 16:40:34 othyro Exp $
#

DISTNAME=	v2.12.9
PKGNAME=	emesene${DISTNAME:S/v/-/1}
CATEGORIES=	chat
MASTER_SITES=	https://github.com/emesene/emesene/archive/
FETCH_USING=	curl
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blog.emesene.org/
COMMENT=	Chat program that connects to different networks
LICENSE=	gnu-gpl-v3 AND gnu-gpl-v2 AND mit AND modified-bsd AND 2-clause-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

WRKSRC=			${WRKDIR}/emesene-2.12.9
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

REPLACE_PYTHON=		codestats.py setup.py

REPLACE_INTERPRETER+=	env
REPLACE.env.old=	.*bin/env python
REPLACE.env.new=	${PYTHONBIN}
REPLACE_FILES.env=	emesene/SingleInstance.py emesene/debugger.py
REPLACE_FILES.env+=	emesene/e3/common/pluginmanager.py
REPLACE_FILES.env+=	emesene/e3/papylib/papyon/papyon/msnp2p/test.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/download_avatars.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/register_account.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/roster_browser.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/set_avatar.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/thirdparty_auth.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/thirdpary_auth.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/user_location.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/user_tune.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/ez_setup.py
REPLACE_FILES.env+=	emesene/e3/xmpp/pyfb/setup.py emesene/emesene.py
REPLACE_FILES.env+=	emesene/extension.py emesene/plugin_base.py
REPLACE_FILES.env+=	emesene/test/e3_example.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/adhoc_provider.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/adhoc_user.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/admin_commands.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/custom_stanzas/custom_stanza_provider.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/custom_stanzas/custom_stanza_user.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/disco_browser.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/echo_client.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/echo_component.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/gtalk_custom_domain.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/ibb_transfer/ibb_receiver.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/ibb_transfer/ibb_sender.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/muc.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/ping.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/proxy_echo_client.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/examples/send_client.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/roster_browser.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/setup.py
REPLACE_FILES.env+=	emesene/e3/xmpp/SleekXMPP/testall.py emesene/emesene

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	python$
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	emesene/e3/xmpp/SleekXMPP/ez_setup.py

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		.*bin/env sh
REPLACE.sh.new=		${SH}
REPLACE_FILES.sh+=	emesene/lintreport.sh

SUBST_CLASSES+=		mandir
SUBST_FILES.mandir=	setup.py
SUBST_MESSAGE.mandir=	Fixing PKGMANDIR path.
SUBST_SED.mandir=	-e "s|share/man|${PKGMANDIR}|1"
SUBST_STAGE.mandir=	pre-configure

INSTALLATION_DIRS+=	bin ${PYSITELIB}/emesene/emesene2/themes/conversations
INSTALLATION_DIRS+=	${PYSITELIB}/emesene/emesene2/themes/emotes
INSTALLATION_DIRS+=	${PYSITELIB}/emesene/emesene2/themes/images
INSTALLATION_DIRS+=	${PYSITELIB}/emesene/emesene2/themes/sounds

post-install:
	${LN} -fhs ${DESTDIR}${PREFIX}/${PYSITELIB}/emesene/emesene ${DESTDIR}${PREFIX}/bin/emesene
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/lib/python${PYVERSSUFFIX}/site-packages
	${CHMOD} g-w ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/emesene.1
	${CHMOD} g-w ${DESTDIR}${PREFIX}/share/applications/emesene.desktop
	${CHMOD} g-w ${DESTDIR}${PREFIX}/share/icons/hicolor/*/apps/emesene.png
	${CHMOD} g-w ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/emesene.svg
	${CHMOD} g-w ${DESTDIR}${PREFIX}/share/pixmaps/emesene.*

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
