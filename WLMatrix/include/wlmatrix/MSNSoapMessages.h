#pragma once
#include <string>
#include <vector>
class MSNPSoapMessages {

    public :
        static const std::vector<std::string> RST2_TOKEN;
        static const std::vector<std::string> RST2_RESPONSE_SUCCESS_TEMPLATE;
        static const std::vector<std::string> RST2_DOMAINS;
        static const std::vector<std::string> AB_FIND_CONTACTS_PAGED_RESPONSE;
        static const std::string AB_FIND_MEMBERSHIP_RESPONSE;
        static const std::string AB_FIND_MEMBERSHIP_MEMBER;
        static const std::string AB_CONTACT_ME_ANNOTATIONS;

};

const std::vector<std::string> MSNPSoapMessages::RST2_TOKEN {"<wst:RequestSecurityTokenResponse><wst:TokenType>urn:passport:compact</wst:TokenType><wsp:AppliesTo xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><wsa:EndpointReference><wsa:Address>", "</wsa:Address></wsa:EndpointReference></wsp:AppliesTo><wst:Lifetime><wsu:Created>", "</wsu:Created><wsu:Expires>", "</wsu:Expires></wst:Lifetime><wst:RequestedSecurityToken><wsse:BinarySecurityToken Id=\"Compact", "\">t=", "</wsse:BinarySecurityToken></wst:RequestedSecurityToken><wst:RequestedTokenReference><wsse:KeyIdentifier ValueType=\"urn:passport:compact\"></wsse:KeyIdentifier><wsse:Reference URI=\"#Compact", "\"></wsse:Reference></wst:RequestedTokenReference><wst:RequestedAttachedReference><wsse:SecurityTokenReference><wsse:Reference URI=\"/DaESnwwMVTTpRTZEoNqUW/Md0k=\"></wsse:Reference></wsse:SecurityTokenReference></wst:RequestedAttachedReference><wst:RequestedUnattachedReference><wsse:SecurityTokenReference><wsse:Reference URI=\"/DaESnwwMVTTpRTZEoNqUW/Md0k=\"></wsse:Reference></wsse:SecurityTokenReference></wst:RequestedUnattachedReference><wst:RequestedProofToken><wst:BinarySecret>", "</wst:BinarySecret></wst:RequestedProofToken></wst:RequestSecurityTokenResponse>"};

const std::vector<std::string> MSNPSoapMessages::RST2_RESPONSE_SUCCESS_TEMPLATE {"<?xml version=\"1.0\" encoding=\"utf-8\" ?><S:Envelope xmlns:S=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><S:Header><wsa:Action xmlns:S=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wsa=\"http://www.w3.org/2005/08/addressing\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" wsu:Id=\"Action\" S:mustUnderstand=\"1\">http://schemas.xmlsoap.org/ws/2005/02/trust/RSTR/Issue</wsa:Action><wsa:To xmlns:S=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wsa=\"http://www.w3.org/2005/08/addressing\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" wsu:Id=\"To\" S:mustUnderstand=\"1\">http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous</wsa:To><wsse:Security S:mustUnderstand=\"1\"><wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" wsu:Id=\"TS\"><wsu:Created>", "</wsu:Created><wsu:Expires>", "</wsu:Expires></wsu:Timestamp></wsse:Security><psf:pp xmlns:psf=\"http://schemas.microsoft.com/Passport/SoapServices/SOAPFault\"><psf:serverVersion>1</psf:serverVersion><psf:PUID>", "</psf:PUID><psf:configVersion>16.000.26889.00</psf:configVersion><psf:uiVersion>3.100.2179.0</psf:uiVersion><psf:mobileConfigVersion>16.000.26208.0</psf:mobileConfigVersion><psf:appDataVersion>1</psf:appDataVersion><psf:authstate>0x48803</psf:authstate><psf:reqstatus>0x0</psf:reqstatus><psf:serverInfo Path=\"Live1\" RollingUpgradeState=\"ExclusiveNew\" LocVersion=\"0\" ServerTime=\"","\">XYZPPLOGN1A23 2017.09.28.12.44.07</psf:serverInfo><psf:cookies/><psf:browserCookies><psf:browserCookie Name=\"MH\" URL=\"http://www.msn.com\">MSFT; path=/; domain=.msn.com; expires=Wed, 30-Dec-2037 16:00:00 GMT</psf:browserCookie><psf:browserCookie Name=\"MHW\" URL=\"http://www.msn.com\">; path=/; domain=.msn.com; expires=Thu, 30-Oct-1980 16:00:00 GMT</psf:browserCookie><psf:browserCookie Name=\"MH\" URL=\"http://www.live.com\">MSFT; path=/; domain=.live.com; expires=Wed, 30-Dec-2037 16:00:00 GMT</psf:browserCookie><psf:browserCookie Name=\"MHW\" URL=\"http://www.live.com\">; path=/; domain=.live.com; expires=Thu, 30-Oct-1980 16:00:00 GMT</psf:browserCookie></psf:browserCookies><psf:credProperties><psf:credProperty Name=\"MainBrandID\">MSFT</psf:credProperty><psf:credProperty Name=\"BrandIDList\"></psf:credProperty><psf:credProperty Name=\"IsWinLiveUser\">true</psf:credProperty><psf:credProperty Name=\"CID\">", "</psf:credProperty><psf:credProperty Name=\"AuthMembername\">", "</psf:credProperty><psf:credProperty Name=\"Country\">US</psf:credProperty><psf:credProperty Name=\"Language\">1033</psf:credProperty><psf:credProperty Name=\"FirstName\">", "</psf:credProperty><psf:credProperty Name=\"LastName\">", "</psf:credProperty><psf:credProperty Name=\"ChildFlags\">00000001</psf:credProperty><psf:credProperty Name=\"Flags\">40100643</psf:credProperty><psf:credProperty Name=\"FlagsV2\">00000000</psf:credProperty><psf:credProperty Name=\"IP\">127.0.0.1</psf:credProperty><psf:credProperty Name=\"AssociatedForStrongAuth\">0</psf:credProperty></psf:credProperties><psf:extProperties><psf:extProperty Name=\"ANON\" Expiry=\"Wed, 30-Dec-2037 16:00:00 GMT\" Domains=\"bing.com;atdmt.com\" IgnoreRememberMe=\"false\">A=B97FB2EE7DB4CE0D0D5B8107FFFFFFFF&amp;E=1542&amp;W=1</psf:extProperty><psf:extProperty Name=\"NAP\" Expiry=\"Wed, 30-Dec-2037 16:00:00 GMT\" Domains=\"bing.com;atdmt.com\" IgnoreRememberMe=\"false\">V=1.9&amp;E=14e8&amp;C=uT838e-8kV7Jbm-HqQel-ETkvE7QSUGh6ywMjZQ9JJyYtNKxtdfCBw&amp;W=1</psf:extProperty><psf:extProperty Name=\"LastUsedCredType\">1</psf:extProperty><psf:extProperty Name=\"WebCredType\">1</psf:extProperty><psf:extProperty Name=\"CID\">", "</psf:extProperty></psf:extProperties><psf:response/></psf:pp></S:Header><S:Body><wst:RequestSecurityTokenResponseCollection xmlns:S=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wst=\"http://schemas.xmlsoap.org/ws/2005/02/trust\" xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" xmlns:saml=\"urn:oasis:names:tc:SAML:1.0:assertion\" xmlns:wsp=\"http://schemas.xmlsoap.org/ws/2004/09/policy\" xmlns:psf=\"http://schemas.microsoft.com/Passport/SoapServices/SOAPFault\"><wst:RequestSecurityTokenResponse><wst:TokenType>urn:passport:legacy</wst:TokenType><wsp:AppliesTo xmlns:wsa=\"http://www.w3.org/2005/08/addressing\"><wsa:EndpointReference><wsa:Address>http://Passport.NET/tb</wsa:Address></wsa:EndpointReference></wsp:AppliesTo><wst:Lifetime><wsu:Created>", "</wsu:Created><wsu:Expires>", "</wsu:Expires></wst:Lifetime><wst:RequestedSecurityToken><EncryptedData xmlns=\"http://www.w3.org/2001/04/xmlenc#\" Id=\"BinaryDAToken0\" Type=\"http://www.w3.org/2001/04/xmlenc#Element\"><EncryptionMethod Algorithm=\"http://www.w3.org/2001/04/xmlenc#tripledes-cbc\"></EncryptionMethod><ds:KeyInfo xmlns:ds=\"http://www.w3.org/2000/09/xmldsig#\"><ds:KeyName>http://Passport.NET/STS</ds:KeyName></ds:KeyInfo><CipherData><CipherValue>Cap26AQZrSyMm2SwwTyJKyqLR9/S+vQWQsaBc5Mv7PwtQDMzup/udOOMMvSu99R284pmiD3IepBXrEMLK5rLrXAf2A6vrP6vYuGA45GCqQdoxusHZcjt9P2B8WyCTVT2cM8jtGqGIfRlU/4WzOLxNrDJwDfOsmilduGAGZfvRPW7/jyXXrnGK7/PWkymX4YDD+ygJfMrPAfvAprvw/HVE6tutKVc9cViTVYy8oHjosQlb8MKn3vKDW1O2ZWQUc47JPl7DkjQaanfNBGe6CL7K1nr6Z/jy7Ay7MjV+KQehmvphSEmCzLrpB4WWn2PdpdTrOcDj+aJfWHeGL4sIPwEKgrKnTQg9QD8CCsm5wew9P/br39OuIfsC6/PFBEHmVThqj0aMxYLRD4K2GoRay6Ab7NftoIP5dnFnclfRxETAoNpTPE2F5Q669QySrdXxBpBSk8GLmdCDMlhiyzSiByrhFQaZRcH8n9i+i289otYuJQ7xPyP19KwT4CRyOiIlh3DSdlBfurMwihQGxN2spU7P4MwckrDKeOyYQhvNm/XWId/oXBqpHbo2yRPiOwL9p1J4AxA4RaJuh77vyhn2lFQaxPDqZd5A8RJjpb2NE2N3UncKLW7GAangdoLbRDMqt51VMZ0la+b/moL61fKvFXinKRHc7PybrG3MWzgXxO/VMKAuXOsB9XnOgl2A524cgiwyg==</CipherValue></CipherData></EncryptedData></wst:RequestedSecurityToken><wst:RequestedAttachedReference><wsse:SecurityTokenReference><wsse:Reference URI=\"2jmj7l5rSw0yVb/vlWAYkK/YBwk=\"></wsse:Reference></wsse:SecurityTokenReference></wst:RequestedAttachedReference><wst:RequestedUnattachedReference><wsse:SecurityTokenReference><wsse:Reference URI=\"2jmj7l5rSw0yVb/vlWAYkK/YBwk=\"></wsse:Reference></wsse:SecurityTokenReference></wst:RequestedUnattachedReference><wst:RequestedProofToken><wst:BinarySecret>tgoPVK67sU36fQKlGLMgWgTXp7oiaQgE</wst:BinarySecret></wst:RequestedProofToken></wst:RequestSecurityTokenResponse>", "</wst:RequestSecurityTokenResponseCollection></S:Body></S:Envelope>"};

const std::vector<std::string> MSNPSoapMessages::RST2_DOMAINS {"messengerclear.live.com", "messenger.msn.com","messengersecure.live.com", "contacts.msn.com", "storage.msn.com", "sup.live.com"};

const std::vector<std::string> MSNPSoapMessages::AB_FIND_CONTACTS_PAGED_RESPONSE {};

const std::string MSNPSoapMessages::AB_CONTACT_ME_ANNOTATIONS = "<Annotation><Name>MSN.IM.MBEA</Name><Value>0</Value></Annotation><Annotation><Name>MSN.IM.GTC</Name><Value>0</Value></Annotation><Annotation><Name>MSN.IM.BLP</Name><Value>1</Value></Annotation>";

const std::string MSNPSoapMessages::AB_FIND_MEMBERSHIP_RESPONSE = "<?xmlversion=\"1.0\"encoding=\"utf-8\"?><soap:Envelopexmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Header><ServiceHeaderxmlns=\"http://www.msn.com/webservices/AddressBook\"><Version>15.01.1408.0000</Version><CacheKey>12r1:VmV4AZeGXqJvemPx973A_p7r6w72NNhyQpzukKLaIV6hBndxsNXKb7zZI0sRgKhI6ClG7T5mnA9ufYtOKNRFtII4vAqvlXGZU7Z2-fcwIZm1309Rr8Ufp1kNEf7-O9qX7nIU18Gfg6b7FBFwAdw-ziCtldVhyoW1ubS5s6TJNasYNDa2SlEyZEo0KZmjmkUD8DvSkU9IaGfk4y_vXRCl39CU5fNaht8MLz4teQ</CacheKey><CacheKeyChanged>true</CacheKeyChanged><PreferredHostName>localhost</PreferredHostName><SessionId>9f5a2db2-fb72-4309-8ac4-4602768ed83b</SessionId></ServiceHeaderxmlns=></soap:Header><soap:Body><FindMembershipResponsexmlns=\"http://www.msn.com/webservices/AddressBook\"><FindMembershipResult><Services><Service><Memberships></Memberships><Info><Handle><Id>1</Id><Type>Messenger</Type><ForeignId/></Handle><InverseRequired>false</InverseRequired><AuthorizationCriteria>Everyone</AuthorizationCriteria><IsBot>false</IsBot></Info><Changes/><LastChange>date</LastChange><Deleted>false</Deleted></Service></Services><OwnerNamespace><Info><Handle><Id>00000000-0000-0000-0000-000000000000</Id><IsPassportNameHidden>false</IsPassportNameHidden><CID>0</CID></Handle><CreatorPuid>0</CreatorPuid><CreatorCID>cid</CreatorCID><CreatorPassportName>name@domain</CreatorPassportName><CircleAttributes><IsPresenceEnabled>false</IsPresenceEnabled><Domain>WindowsLive</Domain></CircleAttributes><MessengerApplicationServiceCreated>false</MessengerApplicationServiceCreated></Info><Changes/><CreateDate>date</CreateDate><LastChange>date</LastChange></OwnerNamespace></FindMembershipResult></FindMembershipResponsexmlns=></soap:Body></soap:Envelope>";

const std::string MSNPSoapMessages::AB_FIND_MEMBERSHIP_MEMBER = "<Member xsi:type=\"PassportMember\"><MembershipId>type/uid</MembershipId><Type>Passport</Type><State>Accepted</State><Deleted>false</Deleted><LastChanged>2020-12-05T10:16:20Z</LastChanged><JoinedDate>2020-12-05T10:05:53Z</JoinedDate><ExpirationDate>0001-01-01T00:00:00</ExpirationDate><Changes /><PassportName>name@domain</PassportName><IsPassportNameHidden>false</IsPassportNameHidden><PassportId>0</PassportId><CID>random</CID><PassportChanges /><LookedupByCID>false</LookedupByCID></Member>";

