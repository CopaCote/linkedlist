#include <string>
#include <vector>

using namespace std;

void split(vector<string> &body, string &full_body)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < full_body.size(); i++)
    {
        if (full_body[i] >= 'A' && full_body[i] <= 'Z')
            full_body[i] += 'a' - 'A';
        else if (full_body[i] >= 'a' && full_body[i] <= 'z')
            continue;
        else
        {
            end = i;
            if (end - start > 0)
                body.push_back(full_body.substr(start, end - start));
            start = i + 1;
        }
    }
}

int solution(string word, vector<string> pages)
{
    vector<vector<string>> links;
    vector<string> urls;
    vector<vector<string>> bodies;
    vector<int> original_scores;
    vector<double> final_scores(pages.size());

    string::size_type n;
    string::size_type p;

    string url_head = "<meta property=\"og:url\" content=\"";
    string link_head = "<a href=\"";
    string link_tail = "</a>";
    string body_head = "<body>";
    string body_tail = "</body>";

    for (int i = 0; i < word.size(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] += 'a' - 'A';

    for (string &s : pages)
    {
        // 1. url 추출
        string url_temp;
        n = s.find(url_head) + url_head.size();
        while (s[n] != '\"')
            url_temp += s[n++];
        urls.push_back(url_temp);

        // 2. 링크 추출 및 href 구문 삭제
        vector<string> page_link;
        n = s.find(link_head);
        while (n != string::npos)
        { // Found Link
            string link;
            int temp = n + link_head.size();
            while (s[temp] != '\"')
                link += s[temp++];
            page_link.push_back(link);

            p = s.find(link_tail, n) + link_tail.size();
            s.replace(n, p - n, "");

            n = s.find(link_head, n + 1);
        }
        links.push_back(page_link);

        // 3. Body 추출
        vector<string> body;
        n = s.find(body_head) + body_head.size();
        p = s.find(body_tail);

        string full_body = s.substr(n, p - n);
        split(body, full_body);
        bodies.push_back(body);

        // 4. 기본점수 측정
        int score = 0;
        for (string &s : body)
            if (s == word)
                score++;
        original_scores.push_back(score);
    }

    // 5. 링크 점수 합산
    for (int i = 0; i < pages.size(); i++)
    {
        for (string &link : links[i])
        {
            for (int j = 0; j < pages.size(); j++)
                if (urls[j] == link)
                {
                    final_scores[j] += (double)original_scores[i] / links[i].size();
                    break;
                }
        }
        final_scores[i] += original_scores[i];
    }

    int max = pages.size() - 1;
    for (int i = pages.size() - 1; i >= 0; i--)
    {
        if (final_scores[i] >= final_scores[max])
            max = i;
    }

    return max;
}